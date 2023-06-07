#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Driving_Back_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitSubState,
    Back1,
    Back2,
    Back3,
    Back4,
    Back5,
    Back6,

} DrivingBackSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "Back1",
    "Back2",
    "Back3",
    "Back4",
    "Back5",
    "Back6",
};

static DrivingBackSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitDrivingBackSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunDrivingBackSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunDrivingBackSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    DrivingBackSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = Back1;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Back1: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_FRONT_CENTER_DETECTED) {
                nextState = Back2;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Back2: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SLOW_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SLOW_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_FRONT_CENTER_NOT_DETECTED) {
                nextState = Back3;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Back3: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SLOW_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SLOW_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_BACK_LEFT_DETECTED || ThisEvent.EventType == TAPE_BACK_RIGHT_DETECTED) {
                nextState = Back4;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Back4: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SLOW_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SLOW_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_BACK_LEFT_NOT_DETECTED || ThisEvent.EventType == TAPE_BACK_RIGHT_NOT_DETECTED) {
                nextState = Back5;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case Back5: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SLOW_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SLOW_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_FRONT_CENTER_DETECTED) {
                nextState = Back6;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Back6: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_MAX_SLOW_SPEED, -BOT_MAX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SLOW_SPEED);
                }
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == TAPE_FRONT_CENTER_NOT_DETECTED) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_BACKING_UP;
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
        RunDrivingBackSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunDrivingBackSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}