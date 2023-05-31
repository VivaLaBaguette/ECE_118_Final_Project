#include <bot_Sensor.h>
#include <BOARD.h>
#include <xc.h>

#include <serial.h>
#include <AD.h>

#define HALL_FRONT_LEFT _RB8
#define HALL_FRONT_RIGHT _RB9
#define HALL_REAR_RIGHT _RB5
#define HALL_REAR_LEFT _RB4

#define HALL_FRONT_LEFT_TRIS _TRISB8 //V07
#define HALL_FRONT_RIGHT_TRIS _TRISB9 //V08
#define HALL_REAR_RIGHT_TRIS _TRISB5 //V06
#define HALL_REAR_LEFT_TRIS _TRISB4 //V05

#define TAPE_FRONT_RIGHT AD_PORTW7
#define TAPE_FRONT_LEFT AD_PORTW8
#define TAPE_FRONT_CENTER AD_PORTW6
#define TAPE_BACK_RIGHT AD_PORTW4
#define TAPE_BACK_LEFT AD_PORTW5

#define BEACON_2KHZ AD_PORTV3 //can cahnge if already used
#define BEACON_15KHZ AD_PORTV4

void Bot_Sensor_Init(void) {
    //for bumpers
    HALL_FRONT_LEFT_TRIS = 1;
    HALL_FRONT_RIGHT_TRIS = 1;
    HALL_REAR_RIGHT_TRIS = 1;
    HALL_REAR_LEFT_TRIS = 1;

    //for tape sensors and beacons
    AD_Init();
    AD_AddPins(TAPE_BACK_LEFT | TAPE_BACK_RIGHT | TAPE_FRONT_CENTER | TAPE_FRONT_LEFT | TAPE_FRONT_RIGHT);

    AD_AddPins(BEACON_15KHZ | BEACON_2KHZ);
}

//returns 10 bit 2kHz Beacon 0 - 1023
uint16_t Bot_2_Beacon(void){
    return AD_ReadADPin(BEACON_2KHZ);
}

//returns 10 bit 1.5kHz Beacon 0 - 1023
uint16_t Bot_15_Beacon(void){
    return AD_ReadADPin(BEACON_15KHZ);
}

//read battery voltage
unsigned int Bot_Battery(void) {

}


//reads tape sensor

unsigned char Bot_Tape_Sensors(void) {

}


//BUMPER STUFF

unsigned char Bot_ReadFrontLeftBumper(void) {
    return HALL_FRONT_LEFT;
}

unsigned char Bot_ReadFrontRightBumper(void) {
    return HALL_FRONT_RIGHT;
}

unsigned char Bot_ReadRearLeftBumper(void) {
    return HALL_REAR_LEFT;
}

unsigned char Bot_ReadRearRightBumper(void) {
    return HALL_REAR_RIGHT;
}

//reads bumper state
// FL, FR, BL, BR

unsigned char Bot_Bumpers(void) {
    return (HALL_FRONT_LEFT + ((HALL_FRONT_RIGHT) << 1)+((HALL_REAR_LEFT) << 2)+((HALL_REAR_RIGHT) << 3));
}