#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Positioning_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    BackUpState,
    RightTrippedState,
    LeftTrippedState,

} PositioningSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "BackUpState",
    "RightTrippedState",
    "LeftTrippedState",
};

static PositioningSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitPositioningSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunPositioningSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunPositioningSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    PositioningSubHSMState_t nextState; // <- change type to correct enum

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
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                ES_Timer_InitTimer(POSITIONING_TIMER, TIMER_POSITIONING_TICK);
            }
            if (ThisEvent.EventType == BACKRIGHT_TRIPPED) {
                nextState = RightTrippedState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED) {
                nextState = LeftTrippedState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case RightTrippedState:
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-BOT_THIRD_SPEED, 0);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_POSITIONING;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {

                break;
            }
            break;
        case LeftTrippedState:
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(0, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_POSITIONING;
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
        RunPositioningSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunPositioningSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}