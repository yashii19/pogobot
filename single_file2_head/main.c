/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 4.1, single file head side.

This file implements the head side of code "Single File Behavior".

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
Charge this script on Robot A
Charge the script "lyna 3 singlefile tail" on other robots.
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



int main(void) {

    // Initialisation robots
    pogobot_init();
    printf("init ok\n");
    
    // Initialisation speed
    //int speedL = 0;
    //int speedR = 0;
    
    // Initialisation LED lights
    int light = 0;
    
    // Initialisation power IR emitter
    pogobot_infrared_set_power(pogobot_infrared_emitter_power_twoThird);
    

    while (1)
    {
      
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
     
    }

}
