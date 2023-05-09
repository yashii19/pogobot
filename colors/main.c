/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 1 straight walk.

This file implements the "Straight Walk Behavior".

It exercises the following features: RGB LED.

Details:
Robot goes full speed on left motors and right motors to walk staight.
- RBG LED is always blue

Testing protocol:
Robot A is placed in the arena, and observed for 100 seconds

*/


#include "pogobot.h"


int main(void) {

    pogobot_init();

    printf("init ok\n");

    int r0 = 0, g0 = 0, b0 = 0;
    int r1 = 0, g1 = 0, b1 = 0;
    int compteur  = 0 ;
    while (1)
    {
      pogobot_led_setColors(r0,g0,b0,0);
      
      compteur ++;
      
      if (compteur / 10 == 0){
        // noir
        r0 = 0;
        g0 = 0;
        b0 = 0;
      }
      
      else if (compteur / 10 == 1){
        // rouge
        r0 = 255;
        g0 = 0;
        b0 = 0;
      }
      
      else if (compteur / 10 == 2){
        // vert
        r0 = 0;
        g0 = 255;
        b0 = 0;
      }
      else if (compteur / 10 == 3){
        // jaune
        r0 = 255;
        g0 = 255;
        b0 = 0;
      }
      else if (compteur / 10 == 4){
        // orange
        r0 = 255;
        g0 = 69;
        b0 = 0;
      }
      else if (compteur / 10 == 5){
        // bleu
        r0 = 0;
        g0 = 0;
        b0 = 255;
      }
      else if (compteur / 10 == 6){
        // violet
        r0 = 128;
        g0 = 0;
        b0 = 128;
      }
      else if (compteur / 10 == 7){
        // rose
        r0 = 255;
        g0 = 20;
        b0 = 147;
      }
      else if (compteur / 10 == 8){
        // marron
        r0 = 139;
        g0 = 69;
        b0 = 19;
      }
      else if (compteur / 100 == 1){
        // blanc
      }


      pogobot_motor_set(motorL, motorFull);
      pogobot_motor_set(motorR, motorFull);
      msleep(1000);

    }

}
