#ifndef AVOID_BACKOBJECT_SUB_H  // <- This should be changed to your own guard on both
#define AVOID_BACKOBJECT_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

uint8_t InitAvoid_BACKOBJECT_SubHSM(void);

ES_Event RunAvoid_BACKOBJECT_SubHSM(ES_Event ThisEvent);

#endif

