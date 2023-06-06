#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Positioning_Left_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    Turn90LeftState,
    ForwardState,
    RightTrippedState,
    LeftTrippedState,
    BackUpState,
    TurnBackState,
    BacktoWallState,
} PositioningLeftSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "Turn90LeftState",
    "ForwardState",
    "RightTrippedState",
    "LeftTrippedState",
    "BackUpState",
    "TurnBackState",
    "BacktoWallState",
};

static PositioningLeftSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitPositioningLeftSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunPositioningLeftSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunPositioningLeftSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    PositioningLeftSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                ES_Timer_InitTimer(POSITIONING_TIMER, TIMER_90DEGREE_TICK);
                nextState = Turn90LeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

                //start a timer here
            }
            break;

        case Turn90LeftState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-BOT_THIRD_SPEED, BOT_THIRD_SPEED);
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = ForwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case ForwardState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == FRONTRIGHT_TRIPPED) {
                nextState = RightTrippedState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == FRONTLEFT_TRIPPED) {
                nextState = LeftTrippedState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == BOTH_FRONT_TRIPPED) {
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case RightTrippedState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(ACQUIRE_TIMER, TIMER_BACKUP_TICK);
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

        case LeftTrippedState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(ACQUIRE_TIMER, TIMER_BACKUP_TICK);
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

        case BackUpState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TurnBackState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
        case TurnBackState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(ACQUIRE_TIMER, 650);
                Bot_Foward(BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = BacktoWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
            
        case BacktoWallState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 400);
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
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
        RunPositioningLeftSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunPositioningLeftSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}