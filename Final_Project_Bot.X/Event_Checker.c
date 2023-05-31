#include "ES_Configure.h"
#include "Event_Checker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"

#include "bot_Sensor.h"
#include "HSM.h"

//Add more headers for sub hsms as needed

#define BATTERY_DISCONNECT_THRESHOLD 175
#define LIGHT_ON_THRESHOLD 350
#define DARK_THRESHOLD 500
/*******************************************************************************
 * EVENTCHECKER_TEST SPECIFIC CODE                                                             *
 ******************************************************************************/

//#define EVENTCHECKER_TEST
#ifdef EVENTCHECKER_TEST
#include <stdio.h>
#define SaveEvent(x) do {eventName=__func__; storedEvent=x;} while (0)

static const char *eventName;
static ES_Event storedEvent;
#endif

uint8_t Beacon_2k(void) {
    static ES_EventTyp_t lastEvent = NOT_DETECTED_2KHZ;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static uint16_t beaconlevel = 0;
    static unsigned int Threshold = LIGHT_ON_THRESHOLD;
    unsigned char BeaconState;
    curEvent = NOT_DETECTED_2KHZ;

    beaconlevel = Bot_2_Beacon();
    
    if (lightLevel >= Threshold) {
//        printf("Helo");
        curEvent = NO_LIGHT_DETECTED;
        Threshold = LIGHT_ON_THRESHOLD;


    } else {
//        printf("asd");
        curEvent = LIGHT_DETECTED;
        Threshold = DARK_THRESHOLD;
        //printf("LightSensorON");
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = lightLevel;
        returnVal = TRUE;
        lastEvent = curEvent; // update history
        
#ifndef SIMPLESERVICE_TEST       // keep this as is for test harness
        PostHSM(thisEvent);
#else
        PostBumper(thisEvent);
#endif   
    }
    
    return (returnVal);
}



uint8_t CheckBattery(void) {
//    static ES_EventTyp_t lastEvent = BATTERY_DISCONNECTED;
//    ES_EventTyp_t curEvent;
//    ES_Event thisEvent;
//    uint8_t returnVal = FALSE;
//    uint16_t batVoltage = AD_ReadADPin(BAT_VOLTAGE); // read the battery voltage
//
//    if (batVoltage > BATTERY_DISCONNECT_THRESHOLD) { // is battery connected?
//        curEvent = BATTERY_CONNECTED;
//    } else {
//        curEvent = BATTERY_DISCONNECTED;
//    }
//    if (curEvent != lastEvent) { // check for change from last time
//        thisEvent.EventType = curEvent;
//        thisEvent.EventParam = batVoltage;
//        returnVal = TRUE;
//        lastEvent = curEvent; // update history
//        
//#ifndef EVENTCHECKER_TEST           // keep this as is for test harness
//        PostHSM(thisEvent);
//#else
//        SaveEvent(thisEvent);
//#endif   
//    }
//    return (returnVal);
}





#ifdef EVENTCHECKER_TEST
#include <stdio.h>
static uint8_t(*EventList[])(void) = {EVENT_CHECK_LIST};

void PrintEvent(void);

void main(void) {
    BOARD_Init();
    /* user initialization code goes here */

    // Do not alter anything below this line
    int i;

    printf("\r\nEvent checking test harness for %s", __FILE__);

    while (1) {
        if (IsTransmitEmpty()) {
            for (i = 0; i< sizeof (EventList) >> 2; i++) {
                if (EventList[i]() == TRUE) {
                    PrintEvent();
                    break;
                }

            }
        }
    }
}

void PrintEvent(void) {
    printf("\r\nFunc: %s\tEvent: %s\tParam: 0x%X", eventName,
            EventNames[storedEvent.EventType], storedEvent.EventParam);
}
#endif