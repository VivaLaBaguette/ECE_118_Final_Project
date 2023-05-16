/*file for movement of the robot
*/

#ifndef BOT_MOVE_H
#define BOT_MOVE_H

#include <BOARD.h>

#define BUMPER_TRIPPED 1
#define BUMPER_NOT_TRIPPED 0

//init bot
void Bot_Move_Init(void);

//control left motor speed
void Bot_Left_Motor(char newSpeed);

//control right motor speed
void Bot_Right_Motor(char newSpeed);

//control flywheel motor
void Bot_FlyWheel(char newSpeed);

//control Load motor 	
void Bot_Loader(char newSpeed);

//set leds
char Bot_LEDSSET(uint16_t pttern);

//number to light 0-12 leds
char Bot_Bar_Graph(uint8_t Number);

#endif