#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "BackwardsLeft_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitSubState,
    BackUpState,
    AvoidWallState,
    RepositioningState,
} BackwardsLeftSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUpState",
    "AvoidWallState",
    "RepositioningState",
};

static BackwardsLeftSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitBackwardsLeftSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunBackwardsLeftSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunBackwardsLeftSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    BackwardsLeftSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case BackUpState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-95, -BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED) {
                ES_Timer_InitTimer(BACKUP_TIMER, 250);
                
                nextState = AvoidWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BACKRIGHT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_BACKWARDS;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AvoidWallState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_HALF_SPEED, BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
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
        RunBackwardsLeftSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunBackwardsLeftSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}