/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 7, dispersion 3

This file implements the code "Dispersion 3 Behavior".

It exercises the following features: RGB LED, low-level infrared
transmission API.

Details:

Robot walks randomly and continuously emits a specific message in each direction.
- RBG LED is blue

When Robot is close to another robot (he gets a message from another robot close to him), he walks slower (speed is divided in 2).
- RBG LED is green

When Robot is close to 2 robots at the same time (gets messages from 2 different robots), he stops.
- RBG LED is red

If there is only one robot left around, he goes back to walking randomly slowly.
If no one is around anymore, he goes back to randomly walking.


Testing protocol:
You need at least 3 robots or more.
Charge this script on all Robots
Place all the robots in the arena in a position where nobody can communicate, and observe for 100 seconds.

 */

#include "pogobot.h"
#include <time.h>
#include <stdio.h>
#include <string.h>


#define robot_name           "robot A"
#define alphabet             "abcdefghijklmnopqrstuvwyz"
#define message_length_bytes ( sizeof( robot_name "front" alphabet ) )
#define MOTORMAX 1023


int main(void) {

    // Initialisation robots
    pogobot_init();
    printf("init ok\n");
    
    // Initialisation speed
    int speedL = 0;
    int speedR = 0;
    

    // When we are alone, the LED light is blue
    pogobot_led_setColor(0,0,255);


    int alone = 0;
    int compteur1 = 0;
    int compteur0 = 0;
    int sender1 = 0;
    int sender0 = 0;
    int lastlast = -1;
    
    
    
    // Initialisation power IR emitter
    pogobot_infrared_set_power(pogobot_infrared_emitter_power_twoThird);
    
    while (1)
    {
      // Get messages
      pogobot_infrared_update();


      // We check if we have any messages
      if ( pogobot_infrared_message_available() ){
        while ( pogobot_infrared_message_available() ){
          
          message_t mr;
          pogobot_infrared_recover_next_message( &mr );

          printf( "RECV: receiver %d, on ir %d, sender %d on ir %d \n", mr.header.receiver_id, mr.header._receiver_ir_index, mr.header._sender_id, mr.header._sender_ir_index );
        
          // Keep the sender ID to know how many ppl are around us
          if (sender0 == mr.header._sender_id || sender0 == 0) {
            sender0 = mr.header._sender_id;
            lastlast = 0;
            compteur0 = 0;
        
          } else if (sender1 == mr.header._sender_id || sender1 == 0) {
            sender1 = mr.header._sender_id;
            lastlast = 1;
            compteur1 = 0;
        
          } else if (lastlast == 1){
            sender0 = mr.header._sender_id;
            lastlast = 0;
            compteur0 = 0;
          } else if (lastlast == 0){
            sender1 = mr.header._sender_id;
            lastlast = 1;
            compteur1 = 0;
          }
        }
      }


      
      printf("SENDER : 0 = %d;  1 = %d \n", sender0, sender1);
      printf("ALONE : %d ", alone);
      
      


      compteur1 ++;
      compteur0 ++;
      
      if ((alone  == 2 || alone == 1) && compteur1 >= 10){
        printf("Deconnecte du sender 1 : on explore.\n");
        sender1 = 0;
      }
      
      if ((alone == 2 || alone == 1) && compteur0 >= 10){
        printf("Deconnecte du sender0 : on explore");
        sender0 = 0;
      }

      if (sender0 != 0 && sender1 != 0 ){
        alone = 2; 
      } else if ((sender0 == 0 && sender1 != 0 )|| (sender1 == 0 && sender0 != 0)){
        alone = 1;
      } else {
        alone = 0;
      }

      if (alone == 2){  
        printf("STOP : on est collé a 2 personnes.\n");
        pogobot_led_setColor(255,0,0);
        
        speedL = 0;
        speedR = 0;
      }

      if (alone == 1){
        printf("1 attache : on explore doucement. \n");
        
        //Green Light
        pogobot_led_setColor(0,255,0);
        
        if (lastlast == 1){
          compteur0 = 0;
        }if(lastlast == 0){
          compteur1 = 0;
        }

        // Compute Random speed for left motor + ride motor
        speedL = rand() % MOTORMAX/2;
        speedR = rand() % MOTORMAX/2;

        

      }
      
      if (alone == 0){
        pogobot_led_setColor(0,0,255);
        printf("Rattaché a personne.\n");


        // Compute Random speed for left motor + ride motor
        speedL = rand() % MOTORMAX;
        speedR = rand() % MOTORMAX;

      }  

      // Set motor with new computed value
      pogobot_motor_set(motorL, speedL);
      pogobot_motor_set(motorR, speedR);
      
      // Send speed values to others
      pogobot_infrared_sendMessageAllDirection(0x1234, (uint8_t *)(&alphabet), sizeof(alphabet));
     
      msleep(1000);
     
    }

}
