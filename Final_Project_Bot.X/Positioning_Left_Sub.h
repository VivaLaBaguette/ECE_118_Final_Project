#ifndef POSITIONING_LEFT_SUB_H  // <- This should be changed to your own guard on both
#define POSITIONING_LEFT_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT



uint8_t InitPositioningLeftSubHSM(void);

ES_Event RunPositioningLeftSubHSM(ES_Event ThisEvent);

#endif