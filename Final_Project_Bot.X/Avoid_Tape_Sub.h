#ifndef AVOID_TAPE_SUB_H  // <- This should be changed to your own guard on both
#define AVOID_TAPE_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitAvoid_TapeSubHSM(void);


ES_Event RunAvoid_TapeSubHSM(ES_Event ThisEvent);

#endif

