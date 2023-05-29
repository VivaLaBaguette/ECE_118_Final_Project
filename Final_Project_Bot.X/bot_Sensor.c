#include <bot_Sensor.h>
#include <BOARD.h>
#include <xc.h>

#include <serial.h>
#include <AD.h>

#define HALL_FRONT_LEFT _RD0
#define HALL_FRONT_RIGHT _RE2
#define HALL_REAR_RIGHT _RD8
#define HALL_REAR_LEFT _RE1

#define HALL_FRONT_LEFT_TRIS _TRISD0 //Z06
#define HALL_FRONT_RIGHT_TRIS _TRISE2 //Z07
#define HALL_REAR_RIGHT_TRIS _TRISD8 //Z08
#define HALL_REAR_LEFT_TRIS _TRISE1 //Z09

void Bot_Sensor_Init(void) {
    HALL_FRONT_LEFT_TRIS = 1;
    HALL_FRONT_RIGHT_TRIS = 1;
    HALL_REAR_RIGHT_TRIS = 1;
    HALL_REAR_LEFT_TRIS = 1;
}

//read battery voltage

unsigned int Bot_Battery(void) {

}



//reads bumper state
unsigned char Bot_Bumpers(void) {
    return (!HALL_FRONT_LEFT + ((!HALL_FRONT_RIGHT) << 1)+((!HALL_REAR_LEFT) << 2)+((!HALL_REAR_RIGHT) << 3));
}

//reads tape sensor

unsigned char Bot_Tape_Sensors(void) {

}


unsigned char Roach_ReadFrontLeftBumper(void)
{
    return !HALL_FRONT_LEFT;
}

unsigned char Roach_ReadFrontRightBumper(void)
{
    return !HALL_FRONT_RIGHT;
}

unsigned char Roach_ReadRearLeftBumper(void)
{
    return !HALL_REAR_LEFT;
}


unsigned char Roach_ReadRearRightBumper(void)
{
    return !HALL_REAR_RIGHT;
}