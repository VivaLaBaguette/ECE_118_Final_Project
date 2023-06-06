#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "AvoidRightWallSub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    BackUpState,
} RightWallSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "BackUpState",
};

static RightWallSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitAvoidRightWallSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunAvoidRightWallSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunAvoidRightWallSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    RightWallSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case BackUpState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(-BOT_MAX_SPEED, -BOT_HALF_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT){
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_AVOIDING;
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
        RunAvoidRightWallSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAvoidRightWallSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}