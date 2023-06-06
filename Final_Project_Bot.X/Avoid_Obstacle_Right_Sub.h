#ifndef AVOID_OBSTACLE_RIGHT_SUB_H  // <- This should be changed to your own guard on both
#define AVOID_OBSTACLE_RIGHT_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitAvoid_Obstacle_RightSubHSM(void);

ES_Event RunAvoid_Obstacle_RightSubHSM(ES_Event ThisEvent);

#endif

