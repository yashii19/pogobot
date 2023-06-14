/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 7, ir2.

This file implements the code "Infrared Mesures Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Robot SENDER continuously emits a specific message in each direction in a frequency given
- each message begins by an id
- each message is saturated

Robot RECEIVER continuously listen. It computes the success scale on 100 messages.
It then light the LED with a color corresponding to the success scale.
Robot BOTH continuously emits as SENDER and continuously listens as RECEIVER.

Testing protocol:
You need at least 2 robots.
Charge this script with SENDER defined on Robot A
Charge the script with RECEIVER defined on Robot B.
Place Robot A in the center of the arena and place Robot B in front of it. You can try different position of Robot B and observe the results.

 */

#include "pogobot.h"
#include "time.h"


#define SENDER
//#define RECEIVER


#define SIZE 380 // number of octet
#define MESUREMENT_SIZE 1024 //1Ko 
unsigned long int total_send = 0;
unsigned long int total_receive = 0;


#define FQCY 30 // Frequence d'envoi des messages. 30Hz | 60 Hz | 90 Hz


uint8_t data[SIZE]; // Data des messages



int main(void) {

    pogobot_init();
    srand( pogobot_helper_getRandSeed() );
	pogobot_infrared_set_power(2);


   

    // init data 
    static int msg_id = 0;
    for (int i = 0; i < SIZE; ++i)
    {
    	data[i] = i%9 + 48;
    }





    int old_cent= 0;
    int cent = 0;
    int count = 0;
    int msg_complete = 1; // msg_complete == 1 if msg received is same as message sent 
	static int msg_counter = 0; // counter of the msg received
	int msg_received[200] = { 0 }; // tableau de reception des msg
	static int tour_counter = 0; // counter of the tour of messages
	float t_success[10] = {0}; // stock les valeurs du taux de succes
	int r = 0, g = 0, b = 0; // couleurs de la LED 0
	
	int ir_sender = 0;
	int old_ir = 0;
	time_reference_t mystopwatch;
	time_reference_t seconds;
	int counter = 0;

	pogobot_stopwatch_reset( &seconds );
    printf("init ok\n");


    while (1)
    {

#ifdef SENDER
    	//start = time(NULL);


    	
    	

    	data[0] = msg_id;
		
		
		//printf("New message sent : %d \n", msg_id);
    	msg_id++;

    	if (msg_id >= 200){
    		msg_id = 0;
    	}
    	pogobot_stopwatch_reset( &mystopwatch );
    	pogobot_infrared_sendMessageAllDirection( 0x1234, (uint8_t *)( data ), SIZE );
		for (int i  = 0; i < 4 ; i++){
			//pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE );
		}
		//pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);

		
 		
 	
		
		uint32_t microseconds = pogobot_stopwatch_get_elapsed_microseconds( &mystopwatch );
		//printf( "Duration: %u microseconds \n ", pogobot_stopwatch_get_elapsed_microseconds(&mystopwatch));
		if (microseconds < 1000000 / FQCY) {
			counter ++;
			//printf("counter %d : All good.\n ", counter);
			pogobot_led_setColors(0,255,0,0);
			msleep((1000000 / FQCY - pogobot_stopwatch_get_elapsed_microseconds( &mystopwatch )) / 1000);
			

		}else{
			//printf("Trop short !\n ");
			pogobot_led_setColors(255,0,0,0);
		}


 		
 		




		


#elif defined RECEIVER
		pogobot_infrared_update();


		/* read reception fifo buffer */
		if ( pogobot_infrared_message_available() ){

			while ( pogobot_infrared_message_available() )
			{
				message_t mr;
				pogobot_infrared_recover_next_message( &mr );
				count = 0;

				//printf("MEssage received by IR %d \n", mr.header._sender_ir_index);

				int msg_size = mr.header.payload_length;

				total_receive += msg_size;
				
				if (old_ir != mr.header._sender_ir_index){
					ir_sender = 2;
				}else {
					ir_sender= 1;
				}
	

				if (msg_received[mr.payload[0]] == 1 ){
					//printf("message already received : %d \n", mr.payload[0]);
					ir_sender = 2;

			
					pogobot_led_setColors(0, 0, 225, 1);
					break;
				}
			
				
				//printf("new message received : %d \n", mr.payload[0]);
				cent = mr.payload[0] / 100 ;
				//printf("cent = %d \n", cent);


				// on verifie que le message est bien le meme que le message envoyé
				for (int i = 1; i < SIZE; ++i){			
					if (data[i] != mr.payload[i]){
						msg_complete = 0;
					}
				}
				pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
				



				// si le msg reçu n'est pas le même, on arrête la lecture.
				if (msg_complete == 0){
					pogobot_led_setColors( rand()%25, rand()%25, 0, 2);
					//printf("Le message reçu ne corresponds pas à celui envoyé. \n");
					break;
				}

				// si le msg recu est le bon
				else {

					if (cent == old_cent){

						msg_received[mr.payload[0]] = 1;
						msg_counter++;
					}
					else{
					
						t_success[tour_counter] = msg_counter;
						//printf("Tour %d : taux de success sur 100 msg : %d \n", tour_counter, msg_counter);
						tour_counter++;

						for (int i = 0; i < 200; i++){
							msg_received[i] = 0;
						}
						msg_received[mr.payload[0]] = 1 ;

						if (msg_counter == 0){
							// rouge
							r = 225;
							g = 0;
							b = 0;
						}
      
						else if (msg_counter < 20){
							// vert
							r = 0;
							g = 225;
							b = 0;
						}
      
						else if (msg_counter < 40){
							// jaune
							r = 225;
							g = 225;
							b = 0;
						}
						else if (msg_counter < 60){
							// orange
							r = 255;
							g = 127;
							b = 0;
						}
						else if (msg_counter < 80){
							// bleu
							r = 0;
							g = 0;
							b = 225;
						}
						else if (msg_counter < 100){
							// violet
							r = 127;
							g = 0;
							b = 255;
						}
						else if (msg_counter == 100){
							// vert
							r = 225;
							g = 225;
							b = 225;
						}

						msg_counter = 1;

					}

					
					

					if (tour_counter >= 10){
						int mean = 0;
						for (int i = 0; i < 10; i++){
							mean = mean + t_success[i];
							//printf("Tour %d : taux de success sur 100 msg : %d \n", i, t_success[i]);
						}

						mean = mean / 10;

						//printf("Moyenne sur 10 tours : %d reçus. \n", mean);
						
						tour_counter = 0;

					}

					old_cent = cent;
					old_ir = mr.header._sender_ir_index;
					

				} 
			}
			
		}else {
			count++;
			

			if (count > 1000){
				r = 255;
				g = 0;
				b = 0;
				count = 0;
				ir_sender = 0;
			}
			
		}
		pogobot_led_setColors(r,g,b,0);
		if (ir_sender == 0){
			pogobot_led_setColors(225, 0, 0, 1);
		}else if (ir_sender == 1){
			pogobot_led_setColors(0, 225, 0, 1);
		}else if (ir_sender == 2){
			pogobot_led_setColors(0, 0, 225, 1);
		}
		

		

#endif 
    }
}