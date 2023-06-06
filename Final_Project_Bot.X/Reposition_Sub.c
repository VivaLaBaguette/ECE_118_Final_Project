#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Reposition_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    WaitState,
    BackwardState,
    AvoidLeftState,
    AvoidRightState,
} RepositionSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "WaitState",
    "BackwardState",
    "AvoidLeftState",
    "AvoidRightState",
};

static RepositionSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitRepositionSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunRepositionSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunRepositionSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    RepositionSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = WaitState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case WaitState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(RELOADING_TIMER, TIMER_RELOAD_TICK);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = BackwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case BackwardState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(RELOADING_TIMER, 400);

                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-97, -BOT_MAX_SPEED);
                }

            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT){
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_REPOSITIONING;
            }

            if (ThisEvent.EventType == BACKLEFT_TRIPPED && Global_Side == RIGHT_SIDE) {
                nextState = AvoidLeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == BACKRIGHT_TRIPPED && Global_Side == LEFT_SIDE) {
                nextState = AvoidRightState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case AvoidLeftState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(BOT_HALF_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = BackwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AvoidRightState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(BOT_MAX_SPEED, BOT_HALF_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = BackwardState;
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
        RunRepositionSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunRepositionSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}