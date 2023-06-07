#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Backwards_Sub.h"
#include "bot_Movement.h"
#include "Driving_Back_Sub.h"

typedef enum {
    InitSubState,
    BackUpState,
    AvoidWallState,
    TankTurnState,
    ResetState,
    TriggeredRight,
    TriggeredLeft,
    PushWallState,

    AvoidBackObject,
} BackwardsSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUpState",
    "AvoidWallState",
    "TankTurnState",
    "ResetState",
    "TriggeredRight",
    "TriggeredLeft",
    "PushWallState",
    "AvoidBackObject"
};

static BackwardsSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitBackwardsSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunBackwardsSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunBackwardsSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    BackwardsSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                InitDrivingBackSubHSM();
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case BackUpState: // in the first state, replace this with correct names
            ThisEvent = RunDrivingBackSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }

            if (ThisEvent.EventType == ES_EXIT) {
            }

            if (ThisEvent.EventType == FINISHED_BACKING_UP) {
                nextState = ResetState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED && Global_Side == LEFT_SIDE) {
                nextState = AvoidWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if ((ThisEvent.EventType == BACKRIGHT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED) && Global_Side == LEFT_SIDE) {
                //AVOID OBSTACLE IN BACK
                
                break;
            }

            if (ThisEvent.EventType == BACKRIGHT_TRIPPED && Global_Side == RIGHT_SIDE) {
                nextState = AvoidWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if ((ThisEvent.EventType == BACKLEFT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED) && Global_Side == RIGHT_SIDE) {
                //AVOID OBSTACLE IN BACK
                
                break;
            }

            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AvoidWallState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 600);
                Bot_Foward(BOT_SIX_SPEED, BOT_SIX_SPEED);

            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TankTurnState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TankTurnState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 100);
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(BOT_SIX_SPEED, -BOT_SIX_SPEED);
                }

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

        case ResetState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED) {
                nextState = TriggeredLeft;
                makeTransition = TRUE;
                ThisEvent.EventType = BACKLEFT_TRIPPED;
                break;
            }
            if (ThisEvent.EventType == BACKRIGHT_TRIPPED) {
                nextState = TriggeredRight;
                makeTransition = TRUE;
                ThisEvent.EventType = BACKRIGHT_TRIPPED;
                break;
            }
            if (ThisEvent.EventType == BOTH_REAR_TRIPPED) {
                nextState = PushWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TriggeredLeft: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 300);
                Bot_Foward(BOT_SLOWEST_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BACKRIGHT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED || ThisEvent.EventType == ES_TIMEOUT) {
                nextState = PushWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
        case TriggeredRight: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 300);
                Bot_Foward(-BOT_THIRD_SPEED, BOT_SLOWEST_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BACKLEFT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED || ThisEvent.EventType == ES_TIMEOUT) {
                nextState = PushWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case PushWallState: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 200);
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {

                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_BACKWARDS;
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
        RunBackwardsSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunBackwardsSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}