#ifndef AVOID_OBSTACLE_LEFT_SUB_H  // <- This should be changed to your own guard on both
#define AVOID_OBSTACLE_LEFT_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitAvoid_Obstacle_LeftSubHSM(void);

ES_Event RunAvoid_Obstacle_LeftSubHSM(ES_Event ThisEvent);

#endif

