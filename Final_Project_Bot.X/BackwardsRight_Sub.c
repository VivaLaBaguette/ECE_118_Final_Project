#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "BackwardsRight_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitSubState,
    BackUpState,
    AvoidWallState,
    RepositioningState,
} BackwardsRightSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUpState",
    "AvoidWallState",
    "RepositioningState",
};

static BackwardsRightSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitBackwardsRightSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunBackwardsRightSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunBackwardsRightSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    BackwardsRightSubHSMState_t nextState; // <- change type to correct enum

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
                Bot_Foward(-BOT_MAX_SPEED, -98);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BACKRIGHT_TRIPPED) {
                ES_Timer_InitTimer(BACKUP_TIMER, 250);
                
                nextState = AvoidWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED) {
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
                Bot_Foward(BOT_THIRD_SPEED, BOT_HALF_SPEED);
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
        RunBackwardsRightSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunBackwardsRightSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}