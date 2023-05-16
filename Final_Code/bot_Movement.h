/*file for movement of the robot
*/

#ifndef BOT_H
#define BOT_H

#include <BOARD.h>

#define BUMPER_TRIPPED 1
#define BUMPER_NOT_TRIPPED 0

void Bot_Init(void);

void Bot_Left_Speed(char newSpeed);

void Bot_Right_Speed(char newSpeed);

unsigned int Bot_Battery(void);

unsigned char Bot_Bumpers(void);

