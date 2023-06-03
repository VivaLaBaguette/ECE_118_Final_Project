#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Towards_Sub.h"
#include "Acquire_Sub.h"
#include "Drive_Foward_Sub.h"
#include "bot_Movement.h"
#include "Positioning_Sub.h"

#include <stdio.h>

typedef enum {
    InitSubState,
    AcquireBeaconState,
    PositionState,
    DriveFowardState,
    AvoidTapeState,
    AvoidBumpState,

} TowardsSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "AcquireBeaconState",
    "PositionState",
    "DriveFowardState",
    "AvoidTapeState",
    "AvoidBumpState",
};

static TowardsSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitTowardsSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunTowardsSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunTowardsSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    TowardsSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                InitAcquireSubHSM();
                InitDriveFowardSubHSM();
                InitPositioningSubHSM();
                nextState = AcquireBeaconState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;


        case AcquireBeaconState: // in the first state, replace this with correct names
            ThisEvent = RunAcquireSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }
            if (ThisEvent.EventType == ES_EXIT) {
            }
            if (ThisEvent.EventType == ACQUIRED_2KHZ) {

                nextState = PositionState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case PositionState: //back up until both back bumpers are tripped
            ThisEvent = RunPositioningSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            //once both bumpers are tripped, continue back with blocking code for just a bit
            if (ThisEvent.EventType == FINISHED_POSITIONING) {
                //then drive foward
                nextState = DriveFowardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case DriveFowardState: //back up until both back bumpers are tripped
            ThisEvent = RunDriveFowardSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FINISHED_NAVIGATION) { //so if towards is done and finished navigating, transition top level to shooting
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_NAVIGATION;
                break;
            }
            //SO EVENTS NEED TO BE CHECKED HERE, FINISHED NAVIGATING, BUMP, AVOID TAPE
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

            
            ///DO THIS CASE LATER, FOR AVOIDING OBSTACLES
        case AvoidBumpState: //back up until both back bumpers are tripped

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_EXIT) {
            }

            //SO EVENTS NEED TO BE CHECKED HERE, FINISHED NAVIGATING, BUMP, AVOID TAPE
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunTowardsSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTowardsSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}