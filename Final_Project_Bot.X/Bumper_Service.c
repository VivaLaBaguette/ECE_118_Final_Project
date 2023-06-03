
#include "BOARD.h"
#include "AD.h"
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "Bumper_Service.h"
#include <stdio.h>

#include "bot_Sensor.h"
#include "HSM.h"

#define TIMER_0_TICKS 50

#define FLEFT_BUMP_MASK (1)
#define FRIGHT_BUMP_MASK (1<<1)
#define RLEFT_BUMP_MASK (1<<2)
#define RRIGHT_BUMP_MASK (1<<3)
//#define NO_BUMPER_TRIPPED 0x00
#define BothFrontBump 0x03
#define BothRearBump 0x0C


static uint8_t MyPriority;

uint8_t InitBumper(uint8_t Priority) {
    ES_Event ThisEvent;

    MyPriority = Priority;

    ThisEvent.EventType = ES_INIT;
    ES_Timer_InitTimer(SIMPLE_SERVICE_TIMER, TIMER_0_TICKS);
    if (ES_PostToService(MyPriority, ThisEvent) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostBumper(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunBumper(ES_Event ThisEvent) {
    ES_Event ReturnEvent;
    ReturnEvent.EventType = ES_NO_EVENT; // assume no errors

    static ES_EventTyp_t lastEvent = NO_BUMPER_TRIPPED;
    ES_EventTyp_t curEvent;

    switch (ThisEvent.EventType) {
        case ES_INIT:
            // No hardware initialization or single time setups, those
            // go in the init function above.
            //
            // This section is used to reset service for some reason
            break;

        case ES_TIMERACTIVE:
        case ES_TIMERSTOPPED:
            break;
        case ES_TIMEOUT:

            //no bumpers are tripped
            if (Bot_Bumpers() == 0x00)

                curEvent = NO_BUMPER_TRIPPED;

                //front right tripped
            else if (Bot_Bumpers() == FRIGHT_BUMP_MASK) {

                curEvent = FRONTRIGHT_TRIPPED;

                // front left tripped    
            } else if (Bot_Bumpers() == FLEFT_BUMP_MASK) {

                curEvent = FRONTLEFT_TRIPPED;

                // rear right tripped    
            } else if (Bot_Bumpers() == RRIGHT_BUMP_MASK) {

                curEvent = BACKRIGHT_TRIPPED;

                // rear left tripped
            } else if (Bot_Bumpers() == RLEFT_BUMP_MASK) {

                curEvent = BACKLEFT_TRIPPED;

                // both front tripped
            } else if (Bot_Bumpers() == BothFrontBump) {

                curEvent = BOTH_FRONT_TRIPPED;

                // both rear tripped
            } else if (Bot_Bumpers() == BothRearBump) {

                curEvent = BOTH_REAR_TRIPPED;

                // both left tripped
            }


            ES_Timer_InitTimer(SIMPLE_SERVICE_TIMER, TIMER_0_TICKS);
            if (curEvent != lastEvent) { // check for change from last time
                ReturnEvent.EventType = curEvent;
                ReturnEvent.EventParam = BUMPER_TRIPPED;
                lastEvent = curEvent; // update history

#ifndef SIMPLESERVICE_TEST           // keep this as is for test harness
                PostHSM(ReturnEvent);
#else
                PostBumper(ReturnEvent);
#endif   
            }
            break;

#ifdef SIMPLESERVICE_TEST     // keep this as is for test harness      
        default:
            printf("\r\nEvent: %s\tParam: 0x%X",
                    EventNames[ThisEvent.EventType], ThisEvent.EventParam);
            break;
#endif
    }

    return ReturnEvent;
}
