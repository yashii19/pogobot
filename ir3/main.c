/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 8, ir3.

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





#define SIZE 64 // number of octet
#define MESUREMENT_SIZE 1024 //1Ko 
unsigned long int total_send = 0;
unsigned long int total_receive = 0;


#define FQCY 30 // Frequence d'envoi des messages. 30Hz | 60 Hz | 90 Hz
#define MAX_NEIGHBORS 1 // Nombre de voisins maximum dans l'experience : 1 (gazeux), 6 (crystal), (12 pire cas)


uint8_t data[SIZE]; // Data des messages



int main(void) {

    pogobot_init();
    srand( pogobot_helper_getRandSeed() );
  

	pogobot_infrared_set_power(2);
	//time_reference_t start;

   

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
    int count = 0;
    int msg_complete = 1; // msg_complete == 1 if msg received is same as message sent 

	static int msg_counter = 0; // counter of the msg received
	int msg_received[MAX_NEIGHBORS][200] = { 0 }; // tableau de reception des msg
	static int tour_counter = 0; // counter of the tour of messages
	float t_success[10] = {0}; // stock les valeurs du taux de succes
	int r = 0, g = 0, b = 0; // couleurs de la LED 0

	int p_emission = 100; // 10, 50, 1
	int neighbors[MAX_NEIGHBORS] = {-1}; // tableau du nombre de voisins
	int neighbors_known = 0;
	int neighbors_nb = 0;
	
	int ir_sender = 0;
	int old_ir = 0;

	time_reference_t mystopwatch;
	time_reference_t t_reception;
	
	time_reference_t seconds;
	int counter = 0;
	pogobot_stopwatch_reset( &t_reception);

	//pogobot_stopwatch_reset( &seconds );
    printf("init ok\n");



    while (1)
    {


    	data[0] = msg_id;
		
		
		//printf("New message sent : %d \n", msg_id);
    	msg_id++;

    	if (msg_id >= 200){
    		msg_id = 0;
    	}

    	pogobot_stopwatch_reset( &timer );
		
		int random = ((float )rand() / (float)21474836.470);
		//printf("random : %d\n", random);
    	if (random <= p_emission){
    		for (int i  = 0; i < 4 ; i++){
				pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE );
				pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);
			}
		}
		//pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);

		




		pogobot_infrared_update();



		/* read reception fifo buffer */
		if ( pogobot_infrared_message_available() ){

			
			message_t mr;
			pogobot_infrared_recover_next_message( &mr );

			//printf("Message recu !! \n");
				

			// on verifie que le message est bien le meme que le message envoyé
			for (int i = 1; i < SIZE; ++i){			
				if (data[i] != mr.payload[i]){
					msg_complete = 0;
				}
			}
			//printf("Le message est bien le même\n");

			// si le msg reçu n'est pas le même, on arrête la lecture.
			if (msg_complete == 0){
				pogobot_led_setColors(255, 0, 0, 0);
				printf("Le message reçu ne corresponds pas à celui envoyé. \n");
				break;
			}

			printf("new message received : %d \n", mr.payload[0]);
			cent = mr.payload[0] / 100 ;
			//printf("cent = %d \n", cent);

		


			int msg_size = mr.header.payload_length;
			total_receive += msg_size;
			int sender_ir = mr.header._sender_ir_index;
			int sender_id = mr.header._sender_id;
			printf("New message received by %d \n number %d ir %d\n", sender_id, mr.payload[0], sender_ir);

			pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);

			if (msg_received[sender_id][mr.payload[0]] == 1){
				printf("message already received\n");
				ir_sender = 2;
			
				pogobot_led_setColors(0, 0, 225, 1);
				break;
			}

			// si le msg recu est le bon
			else {

				pogobot_led_setColors(255,0,0,1);

				if (cent == old_cent){
					msg_received[sender_id][mr.payload[0]] = 1;
					msg_counter++;

					neighbors_known = 0;
					
					for (int i = 0; i < MAX_NEIGHBORS ; i++){
						if (neighbors[i] == sender_id){
							printf("Neighbour already known.\n");
							neighbors_known = 1;
							break;
						}
					}
					if (neighbors_known == 0){
						int i = 0;
						while(i < MAX_NEIGHBORS && neighbors[i] == -1){
							i++;
						}
						neighbors[i] = sender_id;
						neighbors_nb++;
					}
						
				}
				else{						

					for (int i = 0; i < 200; i++){
						msg_received[sender_id][i] = 0;
					}
					msg_received[sender_id][mr.payload[0]] = 1 ;
 
					msg_counter++;

					neighbors_known = 0;
					
					for (int i = 0; i < MAX_NEIGHBORS ; i++){
						if (neighbors[i] == sender_id){
							printf("Neighbour already known.\n");
							neighbors_known = 1;
							break;
						}
					}
					if (neighbors_known == 0){
						int i = 0;
						while(i < MAX_NEIGHBORS && neighbors[i] == -1){
							i++;
						}
						neighbors[i] = sender_id;
						neighbors_nb++;
					}

				}

					
				printf("Nombre de voisins : %d\n", neighbors_nb);

				if ( neighbors_nb == MAX_NEIGHBORS){

					tour_counter++;

					pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 0);

					uint32_t t_final = pogobot_stopwatch_get_elapsed_microseconds( &t_reception );

					printf("Fin du programme. Temps (en microseconds) : %d\n", t_final);
					printf("Nombre de messages reçus : %d | Nombre de robots identifiés : %d \n", msg_counter, neighbors_nb);

					printf("Nombre de ticks : %d | Proba d'emission : %f | Taille de message : %d\n", counter, p_emission, SIZE);

					printf("\n NOUVEAU TOUR : %d\n",tour_counter );

						
					for (int i = 0; i < MAX_NEIGHBORS; i++){
						for (int j= 0; j < 200; j++){
							msg_received[i][j] = 0;
						}
					}

					for (int i = 0; i < MAX_NEIGHBORS ; i++){
						neighbors[i] = -1;		
					}
					neighbors_nb = 0;
				}

				old_cent = cent;
					//old_ir = mr.header._sender_ir_index;

					
					

			} 
			
			
		}else {
			count++;
			

			if (count > 1000){
				pogobot_led_setColors(255,0,0,0);
				count = 0;
				ir_sender = 0;
			}
			
		}
		/*pogobot_led_setColors(r,g,b,0);
		if (ir_sender == 0){
			pogobot_led_setColors(225, 0, 0, 1);
		}else if (ir_sender == 1){
			pogobot_led_setColors(0, 225, 0, 1);
		}else if (ir_sender == 2){
			pogobot_led_setColors(0, 0, 225, 1);
		}*/
		

		
		pogobot_infrared_clear_message_queue();

		uint32_t microseconds = pogobot_stopwatch_get_elapsed_microseconds( &timer );
	
		printf( "Duration: %u microseconds \n ", pogobot_stopwatch_get_elapsed_microseconds(&timer));
		if (microseconds < 1000000 / FQCY) {
			counter ++;
			//printf("counter %d : All good.\n ", counter);
			pogobot_stopwatch_reset(&timer);
			pogobot_led_setColors(0,255,0,0);
			msleep((1000000 / FQCY - pogobot_stopwatch_get_elapsed_microseconds( &timer )) / 1000);
			

		}else{
			//printf("Trop short !\n ");
			pogobot_led_setColors(255,0,0,0);
		}
    }
}