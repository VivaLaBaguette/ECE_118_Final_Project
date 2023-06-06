#ifndef HSM_H  // <- This should be changed to your own guard on both
#define HSM_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

#define DELAY(x)    for (unsigned int wait = 0; wait <= x; wait++) {asm("nop");}
#define delaymed  1830000

#define TIMER_RELOAD_TICK (3000) //10seconds 1second = 100 ticks
#define TIMER_POSITIONING_TICK (1000) 
#define TIMER_SHOOT_POSITIONING_TICK (600)
#define TIMER_SHOOTING_TICK (2000)
#define TIMER_ACQUIRING_TICK (165)
#define TIMER_90DEGREE_TICK (730)
#define TIMER_BACKUP_TICK (400)

#define LEFT_SIDE 0
#define RIGHT_SIDE 1

extern unsigned int Global_Side;

uint8_t InitHSM(uint8_t Priority);

uint8_t PostHSM(ES_Event ThisEvent);

ES_Event RunHSM(ES_Event ThisEvent);

void Bot_Foward(char RSpeed, char LSpeed);

void Bot_Stop(void);

#endif /* HSM_H */