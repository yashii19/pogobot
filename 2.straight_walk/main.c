/**
 * POGOBOT
 *
 * Copyright © 2022 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
**/

/** \file
Pogobot lyna code 2 straight walk.

This file implements the "Straight Walk Behavior".

It exercises the following features: RGB LED.

Details:
Robot goes full speed on left motors and right motors to walk staight.
- RBG LED is always blue

Testing protocol:
Robot is placed in the arena, and observed for 100 seconds

*/


#include "pogobot.h"


int main(void) {

    pogobot_init();

    printf("init ok\n");
    printf(" STRAIGHTWALK BEHAVIOR \n");

    while (1)
    {
      pogobot_led_setColor(0,0,255);
      pogobot_motor_set(motorL, motorFull);
      pogobot_motor_set(motorR, motorFull);
      printf("%d\n",motorFull );
      msleep(1000);

    }

}
