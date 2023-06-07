#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Avoid_Move_Sub.h"
#include "bot_Movement.h"
#include "Driving_Back_Sub.h"

typedef enum {
    InitSubState,
    BackUp1,
    BackUp2,
} AvoidMoveSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUp1",
    "BackUp2",
};

static AvoidMoveSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitAvoidMoveSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunAvoidMoveSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunAvoidMoveSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    AvoidMoveSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = BackUp1;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case BackUp1: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, -76);

                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == TAPE_BACK_LEFT_DETECTED || ThisEvent.EventType == TAPE_BACK_RIGHT_DETECTED) {
                nextState = BackUp2;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case BackUp2: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, -76);

                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == TAPE_BACK_LEFT_NOT_DETECTED || ThisEvent.EventType == TAPE_BACK_RIGHT_NOT_DETECTED) {
                nextState = BackUp1;
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_AVOID_BACKING_UP;
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
        RunAvoidMoveSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAvoidMoveSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}