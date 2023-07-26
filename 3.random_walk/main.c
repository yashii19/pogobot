/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 3 random walk.

This file implements the "Random Walk Behavior".

It exercises the following features: RGB LED.

Details:
Each SLEEPTIME milliseconds, Robot A chooses a random value for left motor and right motor. Each time the value changes, the LED switches colors.
- RBG LED is always blue/red

Testing protocol:
Robot is placed in the arena, and observed for 100 seconds

*/

#include "pogobot.h"
#include <time.h>
#include <stdio.h>
#include <string.h>
#define MOTORMAX 1024
#define SLEEPTIME 1000


int main(void) {

    pogobot_init();
    printf("init ok\n");
    
    int speedL;
    int speedR;
    int light = 0;
    

    while (1)
    {
     
      // la led change de lumière dès qu'on recalcule une vitesse et une direction random
      if (light == 0) {
      	pogobot_led_setColor(0,0,255);
      	light = 1;
      }else{
      	pogobot_led_setColor(255,0,0);
      	light = 0;
      }  
      
      speedL = rand() % MOTORMAX;
      speedR = rand() % MOTORMAX;
      pogobot_motor_set(motorL, speedL);
      pogobot_motor_set(motorR, speedR);
      msleep(SLEEPTIME);

      printf("New speed Left : %d\n", speedL);
      printf("New speed right : %d\n", speedR);
     
    }

}
