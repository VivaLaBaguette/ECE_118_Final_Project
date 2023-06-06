#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Return_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    TinyForwardState,
    Tank_Turn_State,
    ForwardState,
    AvoidRightState,
    AvoidLeftState,
    Forward2State,
} ReturnSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "TinyForwardState",
    "Tank_Turn_State",
    "ForwardState",
    "AvoidRightState",
    "AvoidLeftState",
    "Forward2State",
};

static ReturnSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitReturnSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunReturnSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunReturnSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    ReturnSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = TinyForwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;
        case TinyForwardState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(RETURN_TIMER, 150);
                Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = Tank_Turn_State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
        case Tank_Turn_State: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(RETURN_TIMER, 600);

                if (Global_Side == LEFT_SIDE) { //means going to left side to return
                    Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, BOT_THIRD_SPEED);
                }
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
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(97, BOT_MAX_SPEED);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FRONTLEFT_TRIPPED && Global_Side == RIGHT_SIDE) {
                nextState = AvoidLeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == FRONTRIGHT_TRIPPED && Global_Side == LEFT_SIDE) {
                nextState = AvoidRightState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == TAPE_BACK_LEFT_DETECTED && Global_Side == LEFT_SIDE) {
                nextState = Forward2State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            if (ThisEvent.EventType == TAPE_BACK_RIGHT_DETECTED && Global_Side == RIGHT_SIDE) {
                nextState = Forward2State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Forward2State: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(97, BOT_MAX_SPEED);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FRONTLEFT_TRIPPED && Global_Side == RIGHT_SIDE) {
                nextState = AvoidLeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == FRONTRIGHT_TRIPPED && Global_Side == LEFT_SIDE) {
                nextState = AvoidRightState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == TAPE_BACK_LEFT_NOT_DETECTED && Global_Side == LEFT_SIDE) {
                //                nextState = Forward2State;
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_RETURNING;
            }
            if (ThisEvent.EventType == TAPE_BACK_RIGHT_NOT_DETECTED && Global_Side == RIGHT_SIDE) {
                //                nextState = Forward2State
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_RETURNING;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case AvoidLeftState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(-BOT_HALF_SPEED, -BOT_MAX_SPEED);
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

        case AvoidRightState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 200);
                Bot_Foward(-BOT_MAX_SPEED, -BOT_HALF_SPEED);
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


        default: // all unhandled states fall into here
            break;
    } // end switch on Current State

    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunReturnSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunReturnSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}