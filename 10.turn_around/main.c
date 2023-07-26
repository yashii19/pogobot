/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 10 turn around.

This file implements the "Turn Around Behavior".

It exercises the following features: RGB LED, motor.

Details:
Robot LED lights 5 times during 5 second.
-Robot LED is green at the beginning

Robot walk during 10 seconds following motor values given in definition.
Robot stops during 5 seconds and starts walking again with other motor values.
- RBG LED is blue between experiences

When it finishes all the experiments, robots stops.
-RGB LED is red at the end.

Testing protocol:
Robot are placed in the arena, and observed during the whole experiment.

*/


#include "pogobot.h"
#include "time.h"




int main(void) {

    pogobot_init();

    printf("init ok\n");
    printf(" TURN AROUND BEHAVIOR \n");
    
    int state = 0; // 0 = beginning of experiment | 1 = middle of experiment | 2 = end of experiment
    time_reference_t walking_timer; // set walking timer to track the experiment lasts 10 seconds 
    
    int motorleft[] = {124, 33, 201, 70, 245, 162, 39, 133, 89, 248, 182, 60, 224, 115, 42};
    int motorright[] = {87, 190, 18, 111, 51, 205, 236, 13, 74, 128, 225, 9, 241, 64, 147};

    // Ecarts : [37, 157, 183, 41, 194, 43, 197, 120, 15, 120, 43, 51, 17, 51, 105]


    while (1)
    {
      //beginning of experiment
      if (state == 0){

        int i = 0;
        while (i<5){
          pogobot_led_setColor(0,255,0);
          msleep(700);
          pogobot_led_setColor(0,,0);
          msleep(300);
          i++;
        }

        state = 1;
      }

      // middle of experiment
      if (state == 1){

        for(int i = 0; i < 15; i++){ // while we are still experimenting motor values

          // 10 seconds of walking robot
          pogobot_motor_set(motorL, motorleft[i]);
          pogobot_motor_set(motorR, motorright[i]);
          msleep(10000);

          // 5 seconds of stop
          pogobot_motor_set(motorL, 0);
          pogobot_motor_set(motorR, 0);

          for (int i, i<5;i++) {
            pogobot_led_setColor(0,0,255);
            msleep(700);
            pogobot_led_setColor(0,0,0);
            msleep(300);
          }

        }

        state = 2;
      }

      // end of experiment 
      if (state == 2){
        
        while(1){
          pogobot_led_setColor(255,0,0);
          msleep(700);
          pogobot_led_setColor(0,0,0);
          msleep(300);
        }
      }

    }

}
