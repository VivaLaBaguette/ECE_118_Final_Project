/*file for movement of the robot
 */

#ifndef BOT_SENSOR_H
#define BOT_SENSOR_H

#include <BOARD.h>

#define BUMPER_TRIPPED 0
#define BUMPER_NOT_TRIPPED 1

//init bot sensor
void Bot_Sensor_Init(void);

//read battery voltage
unsigned int Bot_Battery(void);

//reads tape sensor
unsigned char Bot_Tape_Sensors(void);

//returns 10 bit 2kHz Beacon 0 - 1023
uint16_t Bot_2_Beacon(void);

//returns 10 bit 1.5kHz Beacon 0 - 1023
uint16_t Bot_15_Beacon(void);

//BUMPER FUNCTIONS
unsigned char Bot_ReadFrontLeftBumper(void);

unsigned char Bot_ReadFrontRightBumper(void);

unsigned char Bot_ReadRearLeftBumper(void);

unsigned char Bot_ReadRearRightBumper(void);

unsigned char Bot_Bumpers(void);


#endif