#ifndef ServiceBumper  // <- This should be changed to your own guard on both
#define ServiceBumper  //    of these lines

#include "ES_Configure.h"   // defines ES_Event, INIT_EVENT, ENTRY_EVENT, and EXIT_EVENT


uint8_t InitBumper(uint8_t Priority);

uint8_t PostBumper(ES_Event ThisEvent);

ES_Event RunBumper(ES_Event ThisEvent);


#endif
