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

unsigned int Bot_Side(void);

//reads tape sensor
unsigned char Bot_Tape_Sensors(void);

//returns 10 bit 2kHz Beacon 0 - 1023
unsigned int Bot_2_Beacon(void);

//returns 10 bit 1.5kHz Beacon 0 - 1023
unsigned int Bot_15_Beacon(void);

//Tape sensors
//returns their ad value to be dealt with in event checker
unsigned int Read_Tape_Front_Right(void);

unsigned int Read_Tape_Front_Center(void);

unsigned int Read_Tape_Front_Left(void);

unsigned int Read_Tape_Back_Right(void);

unsigned int Read_Tape_Back_Left(void);


//BUMPER FUNCTIONS
unsigned char Bot_Bumpers(void);


#endif