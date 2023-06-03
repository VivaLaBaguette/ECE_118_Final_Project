#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Acquire_Sub.h"
#include "bot_Movement.h"


typedef enum {
    InitState,
    Tank_Turn_State
} AcquireSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "Tank_Turn_State"
};

static AcquireSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitAcquireSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunAcquireSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunAcquireSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    AcquireSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = Tank_Turn_State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Tank_Turn_State: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == DETECTED_2KHZ) {
                makeTransition = FALSE;
                ThisEvent.EventType = ACQUIRED_2KHZ;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunAcquireSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAcquireSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}