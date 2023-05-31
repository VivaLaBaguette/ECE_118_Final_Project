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
        
        printf("%d\r\n", Bot_ReadRearLeftBumper());
//        switch (Bot_Bumpers()) {
//
//            case FLEFT_BUMP_MASK: // Battery Voltage live output
//                printf("Front Left Triggered \r\n");
//                break;
//        }
//        DELAY(delaymed);

    }
    while (1);
}