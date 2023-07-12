/**
 * POGOBOT
 *
 * Copyright © 2023 Sorbonne Université ISIR
 * This file is licensed under the Expat License, sometimes known as the MIT License.
 * Please refer to file LICENCE for details.
 *
 * Nicolas Bredeche 2023-7-7 density exp. (draft)
 *
 * Usage:
 *     DEBUG_LEVEL 3 : display a CSV-formatted output
 *     - CSV: #iteration,#total_nb_of_neighbours,#ticks_to_last_detection
 *   - only iterations when all neighbours are detected are displayed
 *   - MAX_NB_OF_NEIGHBOURS must be carefully set (ie. nb of robots validating full detection).
 *
 * check: 2023-07-11_12h35
**/

#include "pogobot.h"
#include "time.h"

#define FQCY 30 // Frequence d'envoi des messages. 30Hz | 60 Hz | 90 Hz
#define SIZE 64 // number of octet
#define MAX_NB_OF_NEIGHBOURS 2 // max. number of neighbours (ie. w/o self) which the robot should identiy

#define DEBUG_LEVEL 2 // 0: nothing ; 1: timer ; 2: send/receive ; 3: only identification complete

int main(void) {

    // * init (mandatory)
    pogobot_init();
    srand( pogobot_helper_getRandSeed() );
    pogobot_infrared_set_power(2);

    // * init (user-related)

    time_reference_t mystopwatch;

    static int msg_id = 0;

    uint8_t data[SIZE]; // message template
    for (int i = 0; i < SIZE; ++i)
    {
        data[i] = i;
    }

    uint32_t neighbours[MAX_NB_OF_NEIGHBOURS];
    for (int i = 0; i < MAX_NB_OF_NEIGHBOURS; ++i)
    {
        neighbours[i] = -1;
    }

    if ( DEBUG_LEVEL == 2 )
        printf("[INIT] Ok.\n");

    // * main loop

    int iteration = 0;
    int neighbours_count = 0;
    int iteration_zero = 0;

    time_reference_t timer;
    pogobot_stopwatch_reset(&timer);

    while (1)
    {
        pogobot_stopwatch_reset( &mystopwatch );

        // * stats (in terminal)
        //if ( iteration%30 == 0 && DEBUG_LEVEL == 2)
        //    printf("[%d]",iteration);
        if ( DEBUG_LEVEL == 2)
            printf("[%d]\n",iteration);

        // * Get message, and update count of unique neighbours

        pogobot_infrared_update();
        if ( pogobot_infrared_message_available() ) { // read FIFO buffer - new messages?
            int nb_msg = 0;
            int nb_msg_max = 100; // max. number of messages read before cleaning the queue.
            while ( pogobot_infrared_message_available() && nb_msg < nb_msg_max ) // manage new messages
            {
                nb_msg = nb_msg + 1;
                message_t mr;
                pogobot_infrared_recover_next_message( &mr );
                //printf("Message received by IR %d \n", mr.header._sender_ir_index);
                //int msg_size = mr.header.payload_length;
                if ( DEBUG_LEVEL == 2 )
                    printf("[RCVD] Message from robot #%d with stamp %d\n",mr.payload[0],mr.payload[1]);

                // check message content vs expected content (a list of increasing numbers from zero)
                bool check_message = true;
                for (int i = 2; i < SIZE; ++i) {
                    if (mr.payload[i] != data[i]){
                        check_message = false;
                        break;
                    }
                }
                if (check_message == false ) {
                    if ( DEBUG_LEVEL == 2 )
                        printf("[RCVD][error] Message fails content check\n");
                }
                else
                {
                    // register this robot is not seen
                    if ( DEBUG_LEVEL == 2 )
                        printf("[INFO] Checking if this is a new robot\n");
                    bool new_neighbour = true;
                    for (int i = 0; i < neighbours_count; ++i){
                        if ( mr.payload[0] == neighbours[i] )
                            new_neighbour = false;
                    }
                    if ( new_neighbour == true ) {
                        if ( DEBUG_LEVEL == 2 )
                            printf("[INFO] identified new robot (#%d)\n",mr.payload[0]);
                        if ( neighbours_count < MAX_NB_OF_NEIGHBOURS-1 ) // not all neighbours are known
                        {
                            if ( DEBUG_LEVEL == 2 )
                                printf("[INFO] one robot added to the list\n");
                            neighbours[neighbours_count] = mr.payload[0];
                            neighbours_count = neighbours_count + 1;
                        }
                        else // this was the final neighbouring robot to identify -- complete!
                        {
                            if ( DEBUG_LEVEL == 2 )
                                printf("[INFO] %d robot(s) identified out of %d. COMPLETE!\n",MAX_NB_OF_NEIGHBOURS,MAX_NB_OF_NEIGHBOURS);
                            if ( DEBUG_LEVEL == 2 ) {
                                printf("[INFO] Identified %d out of %d robots in %d tick(s)\n",MAX_NB_OF_NEIGHBOURS,MAX_NB_OF_NEIGHBOURS,(iteration-iteration_zero+1));
                            }
                            else
                                if ( DEBUG_LEVEL == 3 || DEBUG_LEVEL == 2) {
                                    printf("%d,%d,%d\n",iteration,MAX_NB_OF_NEIGHBOURS,(iteration-iteration_zero+1));
                                }
                            iteration_zero = iteration;
                            neighbours_count = 0;
                        }
                    }
                    else
                    {
                        if ( DEBUG_LEVEL == 2 )
                            printf("[INFO] robot already known.\n");
                    }
                }
            }
            if ( DEBUG_LEVEL == 2 ) {
                printf("[RCVD] summary: %d message(s) received\n",nb_msg);
            }
        }
        pogobot_infrared_clear_message_queue( );

        // * Send message

        int p_send = 50; // i.e. 0.5
        if ( p_send < rand()%100 )
        {
            data[0] = pogobot_helper_getid();
            data[1] = msg_id;
            for (int i = 2; i < SIZE; ++i) {
                data[i] = i;
            }
            //printf("New message sent : %d \n", msg_id);
            pogobot_infrared_sendMessageAllDirection( 0x1234, (uint8_t *)( data ), SIZE );
            //for (int i  = 0; i < 4 ; i++){
            //    pogobot_infrared_sendMessageOneDirection( i, 0x1234, (uint8_t *)( data ), SIZE );
            //}
            pogobot_led_setColors( rand()%25, rand()%25, rand()%25, 2);
            msg_id = msg_id + 1;
            if ( DEBUG_LEVEL == 2 ) {
                printf("[SEND] 1 message sent\n");
            }
        }

        // * Step synchronize - wait for next step (if not timed out)

        uint32_t microseconds = pogobot_stopwatch_get_elapsed_microseconds( &mystopwatch );

        /*
        if ( microseconds > 2000 )
        {
            printf("#####\n#####\n#####\n#####\n#####\n#####\n#####\n#####\n#####\n");
            msleep( 10000 );
        }
        */

        if (microseconds < 1000000 / FQCY) {
            if ( DEBUG_LEVEL == 1 )
            {
                printf( "[TIME] Step took %lu usec. Sleep until next tick.\n",microseconds);
            }
            pogobot_led_setColors(0,255,0,0);
            msleep( (1000000 / FQCY - microseconds ) / 1000 ); // wait for next step.
        }else{
            if ( DEBUG_LEVEL == 1 )
            {
                printf( "[TIME] Step took %lu usec, should be less than %u usec. [ ### TIME OVERFLOW ### ]\n",microseconds,(1000000 / FQCY));
            }
            pogobot_led_setColors(255,0,0,0); // too slow. Continue directly to next step.
        }
        iteration++;

    }
}

