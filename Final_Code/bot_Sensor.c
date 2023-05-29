#include <bot_Sensor.h>
#include <BOARD.h>
#include <xc.h>

#include <serial.h>
#include <AD.h>

#define HALL_FRONT_LEFT _RB8
#define HALL_FRONT_RIGHT _RD9
#define HALL_REAR_RIGHT _RD8
#define HALL_REAR_LEFT _RB10

#define HALL_FRONT_LEFT_TRIS _TRISB8
#define HALL_FRONT_RIGHT_TRIS _TRISD9
#define HALL_REAR_RIGHT_TRIS _TRISD8
#define HALL_REAR_LEFT_TRIS _TRISB10

#define 2KHZ_SENSOR_DETECTED
#define 1.5KHZ_SENSOR_DETECTED

void bot_Sensor_Init(void){
	HALL_FRONT_LEFT_TRIS = 1;
    HALL_FRONT_RIGHT_TRIS = 1;
    HALL_REAR_RIGHT_TRIS = 1;
    HALL_REAR_LEFT_TRIS = 1;
}

//read battery voltage
unsigned int Bot_Battery(void){
	
}

//reads bumper state
unsigned char Bot_Bumpers(void){
	return (!HALL_FRONT_LEFT + ((!HALL_FRONT_RIGHT) << 1)+((!HALL_REAR_LEFT) << 2)+((!HALL_REAR_RIGHT) << 3));

}

//reads tape sensor
unsigned char Bot_Tape_Sensors(void){
	
}