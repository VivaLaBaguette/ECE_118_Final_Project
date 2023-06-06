#ifndef BACKWARDS_RIGHT_SUB_H  // <- This should be changed to your own guard on both
#define BACKWARDS_RIGHT_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitBackwardsRightSubHSM(void);


ES_Event RunBackwardsRightSubHSM(ES_Event ThisEvent);

#endif

