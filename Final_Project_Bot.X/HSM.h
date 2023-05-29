#ifndef HSM_H  // <- This should be changed to your own guard on both
#define HSM_H  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT

uint8_t InitHSM(uint8_t Priority);

uint8_t PostHSM(ES_Event ThisEvent);

ES_Event RunHSM(ES_Event ThisEvent);

#endif /* HSM_H */