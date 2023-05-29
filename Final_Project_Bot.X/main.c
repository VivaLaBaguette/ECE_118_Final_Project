/*
 * File:   main.c
 * Author: seens
 *
 * Created on April 30, 2023, 8:57 PM
 */

#include <BOARD.h>
#include <serial.h>
#include <AD.h>
#include <LED.h>


#include <bot_Movement.h>
#include <bot_Sensor.h>

#include <stdio.h>
#include <stdbool.h>
#include "xc.h"


#define DELAY(x)    for (unsigned int wait = 0; wait <= x; wait++) {asm("nop");}
#define delaymed  1830000


#define FLEFT_BUMP_MASK (1)
#define FRIGHT_BUMP_MASK (1<<1)
#define RLEFT_BUMP_MASK (1<<2)
#define RRIGHT_BUMP_MASK (1<<3)

int main(void) {

    BOARD_Init();
    SERIAL_Init();
    LED_Init();
    AD_Init();
    Bot_Move_Init();
    Bot_Sensor_Init();



    while (1) {
        



        //        Bot_Left_Motor(BOT_MAX_SPEED);
        //        Bot_Right_Motor(BOT_MAX_SPEED);
        //        DELAY(delaymed * 2);
        //
        //        Bot_Left_Motor(0);
        //        Bot_Right_Motor(0);
        //        DELAY(delaymed);
        //AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

        //        int AVG;
        //
        //        for (int i = 0; i < 100; i++) {
        //            AD_val = AD_ReadADPin(AD_PORTV4) * 6;
        //            AVG += AD_val;
        //        }
        //        printf("%d\r\n", AVG/100);
        //        DELAY(delaymed / 2);
        //        AVG = 0;

        //        AD_val = AD_ReadADPin(AD_PORTV4);
        //        printf("%d\r\n", AD_val);
        //        DELAY(delaymed / 2);

        //        //THIS IS FOR BEACON CHECKOFF
        //                AD_val = AD_ReadADPin(AD_PORTV4) * 6;
        //        
        //                //start hysteresis
        //                if (AD_val >= Threshold) { //if greater than on threshold, turn leds on
        //                    LED_OnBank(LED_BANK1, FULLBANK);
        //                    LED_OnBank(LED_BANK2, FULLBANK);
        //                    LED_OnBank(LED_BANK3, FULLBANK);
        //                    Threshold = OFF_THRESHOLD;
        //                } else {
        //                    LED_OffBank(LED_BANK1, FULLBANK);
        //                    LED_OffBank(LED_BANK2, FULLBANK);
        //                    LED_OffBank(LED_BANK3, FULLBANK);
        //                    Threshold = ON_THRESHOLD;
        //                }
        //                DELAY(delaymed / 2);
        //    }
    }
    while (1);
}