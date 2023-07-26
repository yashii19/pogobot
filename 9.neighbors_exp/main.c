/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 9, neighbors_exp.

This file implements the code "Neighbors Experiment Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Each tick, Robot continuously emits a specific message in each direction in a frequency given
- each message begins by an id
- each message has a defined size.
- the message are sent or not depending on an defined emission probability.

Robot continuously listen.
When he gets a message from an unknown id, he counts it as a new number.
When he gets the amount of neighbors defined, he stops and return the time.


Testing protocol:
You need at least 2 robots.
Charge this script on every robots.
Place Robot A in the center of the arena and place other robots around him.
 */

#include "pogobot.h"
#include "time.h"


#define SIZE_MSG 64 // size messages
#define P_EMISSION 90 //emission probability between 0 and 100
#define TICK 30 // frequency of emission
#define MAX_NEIGHBORS 2 // number of neighbours around

uint8_t data[SIZE_MSG]; // data messages

int main(void) {


	pogobot_init();
    
    // we create the seed for the emission probability
    srand( pogobot_helper_getRandSeed() );

    // set ir power for sending the messages
    pogobot_infrared_set_power(2);
    // Initiation of the data sent into the messages.
    for (int i = 0; i < SIZE_MSG; ++i){
    	data[i] = i%9 + 48;
    }

    
    time_reference_t tick_timer; // set frequency timer to track the frequency of the loop 
    time_reference_t exp_timer; // set frequency timer to track the frequency of the loop 

    
    int msg_counter = 0; // Received message counter.
    int exp_counter = 0; // Experiments counter.
    int tick_counter = 0; // Tick counter.
    int neighbors_counter = 0; // Neighbors perceived counter.
    int neighbor_known; // 1 if the neighbor is already known, 0 otherwise.
    int neighbors[MAX_NEIGHBORS] = {-1}; // table with all the neighbors id already found. 
    
    int random2 = ((float )rand() / (float)21474836.470); // We generate a number between 0 and 100.
    msleep(random2*10);
    
    printf("init ok\n");
    while(1){
    	
    	pogobot_stopwatch_reset(&tick_timer); // We start by putting the frequency timer at 0

    	int random = ((float )rand() / (float)21474836.470); // We generate a number between 0 and 100.
    	
    	if (random <= P_EMISSION){ // If the random number is < to our emission probability, we send a message.
    	
    		
    		// One Direction *4 format
    		//for (int i  = 0; i < 4 ; i++){
			//	pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE_MSG );
			//}
			
			// All Direction format
			pogobot_infrared_sendMessageAllDirection( 0x1234, (uint8_t *)( data ), SIZE_MSG );
			pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);
			//printf("Message sent.\n");
		}


		
		pogobot_infrared_update(); // The robot check if he received a message
		//printf("%d\n", pogobot_infrared_message_available());
		
		if ( pogobot_infrared_message_available() ){

			while(pogobot_infrared_message_available()){
				message_t mr;
				pogobot_infrared_recover_next_message( &mr );

				//printf("Message received.\n");
				msg_counter++; // we add 1 to our message counter

				int sender_id = mr.header._sender_id;
				

				neighbor_known = 0; // first, we check if we already know this neighbor
				for (int i = 0; i < MAX_NEIGHBORS; i++){ 
					if (neighbors[i] == sender_id){
						//printf("Le voisin %d est déjà connu.", sender_id);
						neighbor_known = 1;
					}
				}

				

				if (neighbor_known == 0){ // if we already know it, we stop the loop and ignore the rest.
					int i = 0; // we add the neighbor id to the tab at the first empty case.
					while (i < MAX_NEIGHBORS && neighbors[i] != -1){
						i++;
					}
					neighbors[i] = sender_id;
					neighbors_counter++; // we add 1 to our neighbor counter
					pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
					
					//printf("New neighbor found.\n");

				}
			}
			

		}
		
		pogobot_infrared_clear_message_queue(); // We clear all the messages waiting.

		if (neighbors_counter == MAX_NEIGHBORS){
			exp_counter++; // We add 1 to our experiment counter.
			uint32_t  exp_time = pogobot_stopwatch_get_elapsed_microseconds( &exp_timer ); // Get the time to compute frequency
		
			//printf("Fin du programme. Temps (en microseconds) : %lu\n", exp_time);
			//printf("Nombre de messages reçus : %d | Nombre de robots identifiés : %d \n", msg_counter, neighbors_counter);
			//printf("Nombre de ticks : %d | Proba d'emission : %d | Taille de message : %d\n", tick_counter, P_EMISSION, SIZE_MSG);
			
			
			printf("%d, %lu, %d, %d\n", exp_counter, exp_time, tick_counter, neighbors_counter);

			pogobot_stopwatch_reset(&exp_timer); // We start by putting the frequency timer at 0
			msg_counter = 0;
			neighbors_counter = 0;
			tick_counter = 0;
			for (int i = 0; i < MAX_NEIGHBORS ; i++){
				neighbors[i] = -1;
			}

		}
		
		//if (exp_counter == 10){ // Whe we reach 10 experiences we stop everything.
		//	msleep(10000);
		//	exp_counter = 0;
		//}

		
		uint32_t tick_time = pogobot_stopwatch_get_elapsed_microseconds( &tick_timer ); // Get the time to compute frequency
	
		if (tick_time < 1000000 / TICK) {
			//printf("End of the loop. Under the given frequency. Time = %ld\n", pogobot_stopwatch_get_elapsed_microseconds( &exp_timer ));

			pogobot_led_setColors(0,255,0,0); // Green light if we are under the given frequency
			

			msleep((1000000 / TICK - pogobot_stopwatch_get_elapsed_microseconds( &tick_timer )) / 1000);
		}else{
			printf("End of the loop. Over the given frequency !!\n"); // Red light if we are over the given frequency
			pogobot_led_setColors(255,0,0,0);
		}
		tick_counter++; // We add one to our tick counter.

    	
    }
}
