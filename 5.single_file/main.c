/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 5, single file side.

This file implements the code "Single File Behavior".

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
Charge this script with HEAD on Robot A
Charge the script with TAIL on other robots.
Place all the robot in the arena in a position where everyone can at least communicate with one robot, and observe for 100 seconds

 */

#include "pogobot.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MOTORMAX 1023

#define robot_name           "robot A"
#define alphabet             "abcdefghijklmnopqrstuvwyz"
#define message_length_bytes ( sizeof( robot_name "front" alphabet ) )

#define HEAD
//#define TAIL

int main(void) {

    // Initialisation robots
    pogobot_init();
    printf("init ok\n");
    
    // Initialisation speed
    //int speedL = 0;
    //int speedR = 0;
    
    // Initialisation LED lights
    int light = 0;
    int last_index = -1;

    // Initialisation power IR emitter
    pogobot_infrared_set_power(pogobot_infrared_emitter_power_twoThird);
    

    while (1)
    {
      
#ifdef HEAD
      // Get messages
      pogobot_infrared_update();
 
      // the LED changes colors each time we compute a new speed 
      if (light == 0) {
      	pogobot_led_setColor(0,0,255);
      	light = 1;
      }else{
      	pogobot_led_setColor(255,0,0);
      	light = 0;
      }  
      
      // Compute Random speed for left motor + ride motor
      //speedL = rand() % MOTORMAX;
      //speedR = rand() % MOTORMAX;

      
      //printf("New speed : Left %d Right %d \n", speedL, speedR);
      printf( "TRANS %d bytes %s \n", sizeof(alphabet) , alphabet);
    
      // Set motor with new computed value
      //pogobot_motor_set(motorL, speedL);
      //pogobot_motor_set(motorR, speedR);
      pogobot_motor_set(motorL, MOTORMAX);
      pogobot_motor_set(motorR, MOTORMAX);
      
      // Send speed values to others
      pogobot_infrared_sendMessageAllDirection(0x1234, (uint8_t *)(&alphabet), sizeof(alphabet));
     
      msleep(1000);
     
#ifdef TAIL

      // Get messages
      pogobot_infrared_update();
      
      /* read reception fifo buffer */
      if ( pogobot_infrared_message_available() ){
          
        message_t mr;
        pogobot_infrared_recover_next_message( &mr );

        // the LED changes colors each time we get a new message
        if (light == 0) {
          pogobot_led_setColor(0,0,255);
          light = 1;
        }else{
          pogobot_led_setColor(255,0,0);
          light = 0;
        } 

        printf( "RECV: receiver %d, on ir %d, sender %d on ir %d \n", mr.header.receiver_id, mr.header._receiver_ir_index, mr.header._sender_id, mr.header._sender_ir_index );
        printf( "RECV: len %d [%s]\n", mr.header.payload_length, mr.payload );

        // north side
        if (mr.header._receiver_ir_index == 0) {
          speedR = MOTORMAX/2;
          speedL = MOTORMAX/2;
        }


        // east side
        else if (mr.header._receiver_ir_index == 1) {
          speedL = 3*MOTORMAX/4;
          speedR = MOTORMAX/4;
        }
          
        // south side
        else if (mr.header._receiver_ir_index == 2) {
          speedL = 0;
          speedR =  MOTORMAX;
        }

        // west side
        else if (mr.header._receiver_ir_index == 3) {
          speedL = MOTORMAX/4;
          speedR = 3*MOTORMAX/4;
        }

       /* if (last_index != -1 && last_index != mr.header._receiver_ir_index){
          
          // north east side
          if ((last_index == 0 && mr.header._receiver_ir_index == 1) || (last_index == 1 && mr.header._receiver_ir_index == 0)){
            speedL = MOTORMAX;
            speedR = MOTORMAX/2;
          }
          // north west side
          if ((last_index == 0 && mr.header._receiver_ir_index == 3) || (last_index == 3 && mr.header._receiver_ir_index == 0)){
            speedL = MOTORMAX/2;
            speedR = MOTORMAX;
          }
          // south east side
          if ((last_index == 2 && mr.header._receiver_ir_index == 1) || (last_index == 1 && mr.header._receiver_ir_index == 2)){
            speedL = MOTORMAX;
            speedR = MOTORMAX/4;
          }
          // south west side
          if ((last_index == 2 && mr.header._receiver_ir_index == 3) || (last_index == 3 && mr.header._receiver_ir_index == 2)){
            speedL = MOTORMAX/4;
            speedR = MOTORMAX;
          }

        }*/

        last_index = mr.header._receiver_ir_index;
      }

      // Set motor with new computed value
      pogobot_motor_set(motorL, speedL);
      pogobot_motor_set(motorR, speedR);
      // Send speed values to others

      printf("new speed left %d right %d \n ", speedL, speedR);
      
      
      pogobot_infrared_sendMessageAllDirection(0x1234, (uint8_t *)(&alphabet), sizeof(alphabet));
     
      msleep(1000);
    }

}
