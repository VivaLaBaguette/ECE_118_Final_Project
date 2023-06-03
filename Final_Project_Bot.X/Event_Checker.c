#include "ES_Configure.h"
#include "Event_Checker.h"
#include "ES_Events.h"
#include "serial.h"
#include "AD.h"

#include "bot_Sensor.h"
#include "HSM.h"

//Add more headers for sub hsms as needed

#define BATTERY_DISCONNECT_THRESHOLD 175
#define BEACON_2KHZ_DETECTED_THRESHOLD 570
#define BEACON_2KHZ_NOT_THRESHOLD 535

#define BEACON_15KHZ_DETECTED_THRESHOLD 570
#define BEACON_15KHZ_NOT_THRESHOLD 535

#define TAPE_THRESHOLD 42
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



//START OF FUNCTIONS
//BEACON 2K HYSTERESIS
uint8_t Beacon_2k(void) {
    static ES_EventTyp_t lastEvent = NOT_DETECTED_2KHZ;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int beaconlevel = 0;
    static unsigned int Threshold = BEACON_2KHZ_DETECTED_THRESHOLD;
    unsigned char BeaconState;
    curEvent = NOT_DETECTED_2KHZ;

    beaconlevel = Bot_2_Beacon();
    
    if (beaconlevel >= Threshold) {
//        printf("Helo");
        curEvent = DETECTED_2KHZ;
        Threshold = BEACON_2KHZ_NOT_THRESHOLD;


    } else {
//        printf("asd");
        curEvent = NOT_DETECTED_2KHZ;
        Threshold = BEACON_2KHZ_DETECTED_THRESHOLD;
        //printf("LightSensorON");
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = beaconlevel;
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


uint8_t Beacon_15k(void) {
    static ES_EventTyp_t lastEvent = NOT_DETECTED_15KHZ;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int beaconlevel = 0;
    static unsigned int Threshold = BEACON_15KHZ_DETECTED_THRESHOLD;
    unsigned char BeaconState;
    curEvent = NOT_DETECTED_15KHZ;

    beaconlevel = Bot_15_Beacon();
    
    if (beaconlevel >= Threshold) {
//        printf("Helo");
        curEvent = DETECTED_15KHZ;
        Threshold = BEACON_15KHZ_NOT_THRESHOLD;


    } else {
//        printf("asd");
        curEvent = NOT_DETECTED_15KHZ;
        Threshold = BEACON_15KHZ_DETECTED_THRESHOLD;
        //printf("LightSensorON");
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = beaconlevel;
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



uint8_t Tape_Front_Right(void){
    static ES_EventTyp_t lastEvent = TAPE_FRONT_RIGHT_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int tapelevel = 0;
    unsigned char TapeState;
    curEvent = TAPE_FRONT_RIGHT_NOT_DETECTED;

    tapelevel = Read_Tape_Front_Right();
    
    if (tapelevel >= TAPE_THRESHOLD) {
        curEvent = TAPE_FRONT_RIGHT_DETECTED;

    } else {
        curEvent = TAPE_FRONT_RIGHT_NOT_DETECTED;
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = tapelevel;
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


uint8_t Tape_Front_Left(void){
    static ES_EventTyp_t lastEvent = TAPE_FRONT_LEFT_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int tapelevel = 0;
    unsigned char TapeState;
    curEvent = TAPE_FRONT_LEFT_NOT_DETECTED;

    tapelevel = Read_Tape_Front_Left();
    
    if (tapelevel >= TAPE_THRESHOLD) {
        curEvent = TAPE_FRONT_LEFT_DETECTED;

    } else {
        curEvent = TAPE_FRONT_LEFT_NOT_DETECTED;
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = tapelevel;
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


uint8_t Tape_Front_Center(void){
    static ES_EventTyp_t lastEvent = TAPE_FRONT_CENTER_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int tapelevel = 0;
    unsigned char TapeState;
    curEvent = TAPE_FRONT_CENTER_NOT_DETECTED;

    tapelevel = Read_Tape_Front_Center();
    
    if (tapelevel >= TAPE_THRESHOLD) {
        curEvent = TAPE_FRONT_CENTER_DETECTED;

    } else {
        curEvent = TAPE_FRONT_CENTER_NOT_DETECTED;
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = tapelevel;
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

uint8_t Tape_Back_Left(void){
    static ES_EventTyp_t lastEvent = TAPE_BACK_LEFT_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int tapelevel = 0;
    unsigned char TapeState;
    curEvent = TAPE_BACK_LEFT_NOT_DETECTED;

    tapelevel = Read_Tape_Back_Left();
    
    if (tapelevel >= TAPE_THRESHOLD) {
        curEvent = TAPE_BACK_LEFT_DETECTED;

    } else {
        curEvent = TAPE_BACK_LEFT_NOT_DETECTED;
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = tapelevel;
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

uint8_t Tape_Back_Right(void){
    static ES_EventTyp_t lastEvent = TAPE_BACK_RIGHT_NOT_DETECTED;
    ES_EventTyp_t curEvent;
    ES_Event thisEvent;
    uint8_t returnVal = FALSE;
    
    static unsigned int tapelevel = 0;
    unsigned char TapeState;
    curEvent = TAPE_BACK_RIGHT_NOT_DETECTED;

    tapelevel = Read_Tape_Back_Right();
    
    if (tapelevel >= TAPE_THRESHOLD) {
        curEvent = TAPE_BACK_RIGHT_DETECTED;

    } else {
        curEvent = TAPE_BACK_RIGHT_NOT_DETECTED;
    }

    if (curEvent != lastEvent) { // check for change from last time
        //printf("%s", curEvent );
        thisEvent.EventType = curEvent;
        thisEvent.EventParam = tapelevel;
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