#ifndef RETURN_SUB_H  // <- This should be changed to your own guard on both
#define RETURN_SUB_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitReturnSubHSM(void);

ES_Event RunReturnSubHSM(ES_Event ThisEvent);

#endif

