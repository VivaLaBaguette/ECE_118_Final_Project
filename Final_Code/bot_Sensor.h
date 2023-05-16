/*file for movement of the robot
*/

#ifndef BOT_SENSOR_H
#define BOT_SENSOR_H

#include <BOARD.h>

#define BUMPER_TRIPPED 1
#define BUMPER_NOT_TRIPPED 0

//init bot sensor
void Bot_Sensor_Init(void);

//read battery voltage
unsigned int Bot_Battery(void);

//reads bumper state
unsigned char Bot_Bumpers(void);

//reads tape sensor
unsigned char Bot_Tape_Sensors(void);

#endif