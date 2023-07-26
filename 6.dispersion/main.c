/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 6, dispersion

This file implements the code "Dispersion Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Robot walks randomly and continuously emits a specific message in each direction.
- RBG LED is blue

When Robot gets a message from another robot close to him, he stops.
- RBG LED is red

If no one is around anymore, he goes back to randomly walking.


Testing protocol:
You need at least 2 robots or more.
Charge this script on all Robots
Place all the robots in the arena in a position where nobody can communicate, and observe for 100 seconds.

 */

#include "pogobot.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MOTORMAX 1023

#define robot_name           "robot A"
#define alphabet             "abcdefghijklmnopqrstuvwyz"
#define message_length_bytes ( sizeof( robot_name "front" alphabet ) )


int main(void) {

    // Initialisation robots
    pogobot_init();
    printf("init ok\n");
    
    // Initialisation speed
    int speedL = 0;
    int speedR = 0;


    // When we are alone, the LED light is blue
    int alone = 1;
    int compteur = 0;
    pogobot_led_setColor(0,0,255);
    
    
    // Initialisation power IR emitter
    pogobot_infrared_set_power(pogobot_infrared_emitter_power_twoThird);
    
    while (1)
    {
      // Get messages
      pogobot_infrared_update();

      /* read reception fifo buffer */
      if ( pogobot_infrared_message_available() ){

        compteur = 0; 
        message_t mr;
        pogobot_infrared_recover_next_message( &mr );

        printf( "RECV: receiver %d, on ir %d, sender %d on ir %d \n", mr.header.receiver_id, mr.header._receiver_ir_index, mr.header._sender_id, mr.header._sender_ir_index );

        alone = 0;
        pogobot_led_setColor(255,0,0);
        pogobot_motor_set(motorL, 0);
        pogobot_motor_set(motorR, 0);

      }

      compteur ++;
      if (alone == 0 && compteur >= 10){
        alone = 1 ;
      }


      if (alone == 1){
        pogobot_led_setColor(0,0,255);

        // Compute Random speed for left motor + ride motor
        speedL = rand() % MOTORMAX;
        speedR = rand() % MOTORMAX;


        // Set motor with new computed value
        pogobot_motor_set(motorL, speedL);
        pogobot_motor_set(motorR, speedR);
      }  
      
      // Send speed values to others
      pogobot_infrared_sendMessageAllDirection(0x1234, (uint8_t *)(&alphabet), sizeof(alphabet));
     
      msleep(1000);
     
    }

}
