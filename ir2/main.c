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

Robot SENDER continuously emits a specific message in each direction
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


//#define SENDER
#define RECEIVER
//#define BOTH

#define SIZE 64 // number of octet
#define MESUREMENT_SIZE 1024 //1Ko 
unsigned long int total_send = 0;
unsigned long int total_receive = 0;


#define FQCY 2 // Frequence d'envoi des messages. 6 for 10Hz | 2 for 30 Hz | 1 for 60 Hz


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

    time_reference_t timer;
    pogobot_stopwatch_reset(&timer);

    int old_cent= 0;
    int cent = 0;
    int msg_complete = 1; // msg_complete == 1 if msg received is same as message sent 
	static int msg_counter = 0; // counter of the msg received
	static int tour_counter = 0; // counter of the tour of messages
	float t_success[10] = {0}; // stock les valeurs du taux de succes
	int first_time = 1; // state première fois


    printf("init ok\n");

    while (1)
    {

#ifdef SENDER

    	data[0] = msg_id;
		
		
		printf("New message sent : %d \n", msg_id);
    	msg_id++;

    	if (msg_id >= 200){
    		msg_id = 0;
    	}

		for (int i  = 0; i < 4 ; i++){
			pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE );
		}
		pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
		
		msleep(FQCY);


#elif defined RECEIVER
		pogobot_infrared_update();

		/* read reception fifo buffer */
		if ( pogobot_infrared_message_available() )
		{
			while ( pogobot_infrared_message_available() )
			{
				message_t mr;
				pogobot_infrared_recover_next_message( &mr );

				int msg_size = mr.header.payload_length;
				total_receive += msg_size;
				
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
					//printf("Le message reçu ne corresponds pas à celui envoyé. \n");
					break;
				}

				// si le msg recu est le bon
				else {

					if (cent == old_cent){
						msg_counter++;
						//printf("msg_counter : %d \n", msg_counter);
					}

					else{
						t_success[tour_counter] = msg_counter;
						printf("Tour %d : taux de success sur 100 msg : %d \n", tour_counter, msg_counter);
						pogobot_led_setColors(0,0,255, 0);
						tour_counter++;
						msg_counter = 0;
					}

					if (tour_counter >= 10){
						int mean = 0;
						for (int i = 0; i < 10; i++){
							mean = mean + t_success[i];
							//printf("Tour %d : taux de success sur 100 msg : %d \n", i, t_success[i]);
						}

						mean = mean / 10;

						printf("Moyenne sur 10 tours : %d reçus. \n", mean);
						pogobot_led_setColors(255,255,255,0);
						tour_counter = 0;
					}

					old_cent = cent;

				} 
			}
		}

#endif 
    }
}
