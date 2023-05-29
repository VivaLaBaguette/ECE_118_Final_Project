#include <bot_Movement.h>
#include <BOARD.h>
#include <xc.h>

#include <pwm.h>
#include <serial.h>
#include <AD.h>

#include <stdio.h>

#define LEFT_PWM PWM_PORTY12	//Left Motor Speed Control
#define RIGHT_PWM PWM_PORTX11	//Right Motor Speed Control


#define LEFT_DIR LATDbits.LATD2
#define LEFT_DIR_INV LATEbits.LATE6

#define RIGHT_DIR LATFbits.LATF6
#define RIGHT_DIR_INV LATDbits.LATD7

#define LEFT_DIR_TRIS _TRISD2
#define LEFT_DIR_INV_TRIS _TRISE6

#define RIGHT_DIR_TRIS _TRISF6
#define RIGHT_DIR_INV_TRIS _TRISD7


//TRIS - 0 is output, 1 is input
//LAT - sets the pin. 1 or 0

//#define FLYWHEEL_PWM PWM_PORTY04 //Flywheel speed control
//#define LOADER_PWM PWM_PORTZ06	//Loader Speed Control

void Bot_Move_Init(void) {
    //setting the speed pin controls for the motors
    PWM_Init();
    PWM_SetFrequency(1000);
    PWM_AddPins(LEFT_PWM | RIGHT_PWM);

    LEFT_DIR_TRIS = 0;
    LEFT_DIR_INV_TRIS = 0;
    RIGHT_DIR_TRIS = 0;
    RIGHT_DIR_INV_TRIS = 0;

    LEFT_DIR = 0;
    LEFT_DIR_INV = ~LEFT_DIR;
    RIGHT_DIR = 0;
    RIGHT_DIR_INV = ~RIGHT_DIR;

}

char Bot_Left_Motor(char newSpeed) {
    if ((newSpeed < -BOT_MAX_SPEED) || (newSpeed > BOT_MAX_SPEED)) {
        return (ERROR);
    }
    newSpeed = -newSpeed;

    if (newSpeed < 0) {
        LEFT_DIR = 0;
        newSpeed = newSpeed * (-1); // set speed to a positive value
    } else {
        LEFT_DIR = 1;
    }
    LEFT_DIR_INV = ~(LEFT_DIR);
    if (PWM_SetDutyCycle(LEFT_PWM, newSpeed * (MAX_PWM / BOT_MAX_SPEED)) == ERROR) {
        //printf("ERROR: setting channel 1 speed!\n");
        return (ERROR);
    }
    return (SUCCESS);
}

char Bot_Right_Motor(char newSpeed) {
    if ((newSpeed < -BOT_MAX_SPEED) || (newSpeed > BOT_MAX_SPEED)) {
        return (ERROR);
    }
    if (newSpeed < 0) {
        RIGHT_DIR = 0;
        newSpeed = newSpeed * (-1); // set speed to a positive value
    } else {
        RIGHT_DIR = 1;
    }
    RIGHT_DIR_INV = ~(RIGHT_DIR);
    if (PWM_SetDutyCycle(RIGHT_PWM, newSpeed * (MAX_PWM / BOT_MAX_SPEED)) == ERROR) {
        //puts("\aERROR: setting channel 1 speed!\n");
        return (ERROR);
    }
    return (SUCCESS);
}

char Bot_Flywheel(char newSpeed) {

}

char Bot_Loader(char newSpeed) {

}

char Bot_LEDSSET(uint16_t pattern) {

}

char Bot_Bar_Graph(uint8_t Number) {

}