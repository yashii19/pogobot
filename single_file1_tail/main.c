/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 3.2, single file tail side.

This file implements the tail side of code "Single File Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Robot A walks randomly and continuously emits a specific message in each direction
- each message contains:
  - speed of the left motor
  - speed of the right motor
- RBG LED is always red/blue
Other robots (B, C, ...) continuously listen. When they receive a message, they apply the value received to their motorspeed and emits the same message in each direction.

Testing protocol:
You need at least 2 robots or more.
Charge the script "lyna 3 single file head" on Robot A
Charge the script "lyna 3 singlefile tail" on other robots.
Place all the robot in the arena in a position where everyone can at least communicate with one robot, and observe for 100 seconds

 */

#include "pogobot.h"
#include <time.h>
#include <stdio.h>
#include <string.h>


#define robot_name           "robot A"

// Speed structure
typedef struct my_speed_t
{
    uint16_t count;
    uint16_t left;
    uint16_t right;
} my_speed_t;


int main(void) {

    // Initialisation robots
    pogobot_init();
    printf("init ok\n");
    
    // Initialisation speed


    struct my_speed_t my_speed = {.count = 0, .left = 0, .right = 0};
    
    // Initialisation LED lights
    int light = 0;
    

    
    while (1)
    {
      // Get messages
      pogobot_infrared_update();
      
      /* read reception fifo buffer */
      if ( pogobot_infrared_message_available() ){
      		
        message_t mr;
      	pogobot_infrared_recover_next_message( &mr );
      		
        my_speed_t *recept = (my_speed_t *)(&( mr.payload ));
        
        if (recept->count > my_speed.count) {
          // the LED changes colors each time we get a new message
          if (light == 0) {
            pogobot_led_setColor(0,0,255);
            light = 1;
          }else{
            pogobot_led_setColor(255,0,0);
            light = 0;
          } 
          
          printf( "RECV: receiver %d, on ir %d, sender %d on ir %d ", mr.header.receiver_id, mr.header._receiver_ir_index, mr.header._sender_id, mr.header._sender_ir_index );
          printf( "RECV: len %d [%s]\n", mr.header.payload_length, mr.payload );

          
          my_speed.count = recept->count;     
          my_speed.left= recept->left;
          my_speed.right = recept->right;
          printf("new values : %d %d %d", my_speed.count, my_speed.left, my_speed.right);
        }
      }
      // clean queue
      pogobot_infrared_clear_message_queue();           


      // Set motor with new computed value
      pogobot_motor_set(motorL, my_speed.left);
      pogobot_motor_set(motorR, my_speed.right);
      // Send speed values to others
      pogobot_infrared_sendMessageAllDirection(0x1234, (uint8_t *)(&my_speed), sizeof(my_speed ));
     
      msleep(1000);
     
    }

}
