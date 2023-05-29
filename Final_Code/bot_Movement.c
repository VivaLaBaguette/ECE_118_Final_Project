#include <bot_Movement.h>
#include <BOARD.h>
#include <xc.h>

#include <pwm.h>
#include <serial.h>
#include <AD.h>


#define LEFT_PWM PWM_PORTY10	//Left Motor Speed Control
#define RIGHT_PWM PWM_PORTY12	//Right Motor Speed Control

//left direction
#define LEFT_DIR LATBbits.LATB3
#define LEFT_DIR_INV LATBbits.LATB2

//right direction
#define RIGHT_DIR LATEbits.LATE5
#define RIGHT_DIR_INV LATEbits.LATE6

#define LEFT_DIR_TRIS _TRISB3
#define LEFT_DIR_INV_TRIS _TRISB2
#define RIGHT_DIR_TRIS _TRISE5
#define RIGHT_DIR_INV_TRIS _TRISE6

//TRIS - 0 is output, 1 is input
//LAT - sets the pin. 1 or 0

#define FLYWHEEL_PWM PWM_PORTY04 //Flywheel speed control
#define LOADER_PWM PWM_PORTZ06	//Loader Speed Control

#define FLYWHEEL_TRIS _TRISB4
#define FLYWHEEL_LAT LATBbits.LATB4

void Bot_Move_Init(void){
	
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

char Bot_Left_Motor(char newSpeed){
	
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
    if (PWM_SetDutyCycle(LEFT_PWM, newSpeed * (MAX_PWM / ROACH_MAX_SPEED)) == ERROR) {
        return (ERROR);
    }
    return (SUCCESS);
}

char Bot_Right_Motor(char newSpeed){
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
    if (PWM_SetDutyCycle(RIGHT_PWM, newSpeed * (MAX_PWM / ROACH_MAX_SPEED)) == ERROR) {
        //puts("\aERROR: setting channel 1 speed!\n");
        return (ERROR);
    }
    return (SUCCESS);
}


char Bot_Flywheel(char newSpeed){

}

char Bot_Loader(char newSpeed){

}

char Bot_LEDSSET(uint16_t pattern){
	
}

char Bot_Bar_Graph(uint8_t Number){
	
}