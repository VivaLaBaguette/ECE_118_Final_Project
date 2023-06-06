/*file for movement of the robot
*/

#ifndef BOT_MOVE_H
#define BOT_MOVE_H

#include <BOARD.h>

#define BOT_MAX_SPEED 100
#define BOT_MAX_SLOW_SPEED 98

#define BOT_THIRD_SPEED 75
#define BOT_SIX_SPEED 63
#define BOT_HALF_SPEED 50
#define BOT_SLOWEST_SPEED 45

#define BOT_SLOW_SPEED 30

#define BOT_LEFT_MAX_SPEED 99.5

#define BOT_LOADER_SPEED 20
#define BOT_FLYWHEEL_SPEED 70

//init bot
void Bot_Move_Init(void);

//control left motor speed
char Bot_Left_Motor(char newSpeed);

//control right motor speed
char Bot_Right_Motor(char newSpeed);

//control flywheel motor
char Bot_Flywheel(char newSpeed);

//control Load motor 	
char Bot_Loader(char newSpeed);

//set leds
char Bot_LEDSSET(uint16_t pttern);

//number to light 0-12 leds
char Bot_Bar_Graph(uint8_t Number);

#endif