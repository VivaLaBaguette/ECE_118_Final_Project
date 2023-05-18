/*
 * File:   main.c
 * Author: seens
 *
 * Created on April 30, 2023, 8:57 PM
 */

#include <BOARD.h>
#include <stdio.h>
#include <serial.h>
#include <AD.h>
#include <LED.h>
#include "xc.h"
#include <stdbool.h>

#define DELAY(x)    for (unsigned int wait = 0; wait <= x; wait++) {asm("nop");}
#define delaymed  183000

#define ON_THRESHOLD 800
#define OFF_THRESHOLD 600

#define FULLBANK 0x0F
#define ALL_LED_BANKS (LED_BANK1|LED_BANK2|LED_BANK3)
#define NOBANK 0x00

unsigned char LED_ADD(unsigned int AD_val);

int main(void) {

    BOARD_Init();
    SERIAL_Init();
    LED_Init();
    AD_Init();

    LED_AddBanks(LED_BANK1 | LED_BANK2 | LED_BANK3);

    AD_AddPins(AD_PORTV4);
    LED_OffBank(LED_BANK1, FULLBANK);
    LED_OffBank(LED_BANK2, FULLBANK);
    LED_OffBank(LED_BANK3, FULLBANK);

    uint16_t AD_val;

    unsigned int Threshold = ON_THRESHOLD;

    while (1) {

        AD_val = AD_ReadADPin(AD_PORTV4);
        printf("2kHz: %d\r\n", AD_val);


        //start hysteresis
        if (AD_val >= Threshold) { //if greater than on threshold, turn leds on
            LED_OnBank(LED_BANK1, FULLBANK);
            LED_OnBank(LED_BANK2, FULLBANK);
            LED_OnBank(LED_BANK3, FULLBANK);
            Threshold = OFF_THRESHOLD;
        } else {
            LED_OffBank(LED_BANK1, FULLBANK);
            LED_OffBank(LED_BANK2, FULLBANK);
            LED_OffBank(LED_BANK3, FULLBANK);
            Threshold = ON_THRESHOLD;
        }
        DELAY(delaymed / 2);
    }
    while (1);
}