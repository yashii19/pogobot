/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 6, ir.

This file implements the code "Infrared Mesures Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Robot SENDER continuously emits a specific message in each direction
- each message is saturated
Robot RECEIVER continuously listen. When they receive a message, they change their LED 0 color.
Robot BOTH continuously emits as SENDER and continuously listens as RECEIVER.

Testing protocol:
You need at least 2 robots.
Charge this script with SENDER defined on Robot A
Charge the script with RECEIVER defined on Robot B.
Place Robot A in the center of the arena and place Robot B in front of it. You can try different position of Robot B and observe the results.

 */

#include "pogobot.h"


#define SENDER
//#define RECEIVER
//#define BOTH

#define SIZE 64 // number of octet
#define MESUREMENT_SIZE 1024 //1Ko 
unsigned long int total_send = 0;
unsigned long int total_receive = 0;

uint8_t data[SIZE];



int main(void) {

    pogobot_init();
    srand( pogobot_helper_getRandSeed() );
	pogobot_infrared_set_power(2);

    // init data 
    int i;
    for (i = 0; i < SIZE; ++i)
    {
    	data[i] = i%9 + 48;
    }

    time_reference_t timer;
    pogobot_stopwatch_reset(&timer);

    printf("init ok\n");

    while (1)
    {

#ifdef SENDER
		for (int i  = 0; i < 4 ; i++){
			pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE );
		}
		pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
		total_send += SIZE;
		if (total_send%(1000*SIZE) == 0)
		{
			pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 0);
		}
		pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);

		if (total_send == MESUREMENT_SIZE )
		{
			int32_t time = pogobot_stopwatch_get_elapsed_microseconds(&timer);
			printf("%ld us for 1Ko\n", time);

			total_send = 0;
			pogobot_stopwatch_reset(&timer);
		}
		msleep(1);


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
				

				if (total_receive%(1000*SIZE) == 0)
				{
					pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 0);
				}

				pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);

				if (total_receive == MESUREMENT_SIZE )
				{
					int32_t time = pogobot_stopwatch_get_elapsed_microseconds(&timer);
					slip_error_counter_s error_counter;
					pogobot_infrared_get_receiver_error_counter( &error_counter, mr.header._receiver_ir_index );
					printf("%ld us for 1Ko (%d, %ld, %ld)\n", time, mr.header.receiver_id, error_counter.crc_mismatch_counter, error_counter.overflow_counter);
					pogobot_infrared_reset_receiver_error_counter();

					total_receive = 0;
					pogobot_stopwatch_reset(&timer);

					int ir = mr.header._sender_ir_index;
					printf("%d \n", ir);
					
					if (ir == 0){
						pogobot_led_setColors(0,0,255,0);
					}
					else if (ir == 1){
						pogobot_led_setColors(255,255,255,0);
					}
					else if (ir == 2){
						pogobot_led_setColors(255,0,0,0);
					}
					else if (ir == 3){
						pogobot_led_setColors(0,255,0,0);
					}
				}
			}
			//pogobot_infrared_clear_message_queue();
		}else{
			pogobot_led_setColors(0,0,0,0);
		}
		//msleep(10);

       


#elif defined BOTH
		pogobot_infrared_sendMessageAllDirection( 0x1234, (uint8_t *)( data ), SIZE );

		pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
		total_send += SIZE;
		if (total_send%(1000*SIZE) == 0)
		{
			pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);
		}

		if (total_send == MESUREMENT_SIZE )
		{
			int32_t time = pogobot_stopwatch_get_elapsed_microseconds(&timer);
			printf("send %ld us for 1Ko\n", time);

			total_send = 0;
			pogobot_stopwatch_reset(&timer);
		}

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



				if (total_receive%(1000*SIZE) == 0)
				{
					pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);

				}

				pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 1);

				if (total_receive == MESUREMENT_SIZE )
				{
					int32_t time = pogobot_stopwatch_get_elapsed_microseconds(&timer);
					slip_error_counter_s error_counter;
					pogobot_infrared_get_receiver_error_counter( &error_counter, mr.header._receiver_ir_index );
					pogobot_infrared_reset_receiver_error_counter();
					printf("receive %ld us for 1Ko (%d, %ld, %ld)\n", time, mr.header.receiver_id, error_counter.crc_mismatch_counter, error_counter.overflow_counter);
					
					
					total_receive = 0;
					pogobot_stopwatch_reset(&timer);
				}

				
			}
			//pogobot_infrared_clear_message_queue();
		}else{
					pogobot_led_setColors(0,0,0,0);
				}
		msleep(1);	
#endif 
    }
}
