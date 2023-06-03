#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Drive_Foward_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitState,
    Drive1,
    Drive2,
    Drive3,
    Drive4,
    Drive5,
    Drive6,
    Drive7,

} DriveFowardSubHSMState_t;

static const char *StateNames[] = {
    "InitState",
    "Drive1",
    "Drive2",
    "Drive3",
    "Drive4",
    "Drive5",
    "Drive6",
    "Drive7",
};

static DriveFowardSubHSMState_t CurrentState = InitState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitDriveFowardSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitState;
    returnEvent = RunDriveFowardSubHSM(INIT_EVENT);

    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }

    return FALSE;
}

ES_Event RunDriveFowardSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    DriveFowardSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                nextState = Drive1;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Drive1: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_FRONT_CENTER_DETECTED) {
                nextState = Drive2;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Drive2: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_FRONT_CENTER_NOT_DETECTED) {
                nextState = Drive3;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case Drive3: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_BACK_RIGHT_DETECTED || ThisEvent.EventType == TAPE_BACK_LEFT_DETECTED) {
                nextState = Drive4;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Drive4: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_BACK_RIGHT_NOT_DETECTED || ThisEvent.EventType == TAPE_BACK_LEFT_NOT_DETECTED) {
                nextState = Drive5;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Drive5: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_FRONT_CENTER_DETECTED) {
                nextState = Drive6;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Drive6: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_FRONT_CENTER_NOT_DETECTED) {
                nextState = Drive7;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Drive7: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == TAPE_BACK_RIGHT_DETECTED || ThisEvent.EventType == TAPE_BACK_LEFT_DETECTED) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_NAVIGATION;
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
        RunDriveFowardSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunDriveFowardSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end

    return ThisEvent;
}