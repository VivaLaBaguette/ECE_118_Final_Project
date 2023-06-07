#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Avoid_BackObject_Sub.h"
#include "bot_Movement.h"
#include "Acquire_Sub.h"

typedef enum {
    InitSubState,
	TinyForwardState,
	AcquireState,
	TurnToOtherSideState,
	ForwardToSideState,
	TinyBackState,


} Avoid_BackObject_SubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",


};

static Avoid_BackObject_SubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitAvoid_BackObject_SubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunAvoid_BackObject_SubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunAvoid_BackObject_SubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    Avoid_BackObject_SubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                InitAvoidMoveSubHSM();
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case BackUpState: //go forward to goal

            ThisEvent = RunAvoidMoveSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {

            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == BACKLEFT_TRIPPED || ThisEvent.EventType == BACKLEFT_TRIPPED || ThisEvent.EventType == BOTH_REAR_TRIPPED) {
                nextState = AvoidWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            
            if (ThisEvent.EventType == FINISHED_AVOID_BACKING_UP) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = ReloadBack;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case ReloadBack: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-80, -BOT_THIRD_SPEED);

                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_THIRD_SPEED, -80);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == BACKLEFT_TRIPPED) {
                nextState = BackLeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == BACKRIGHT_TRIPPED) {
                nextState = BackRightState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BOTH_REAR_TRIPPED) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = Flatten;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
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

        case BackLeftState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 150);
                Bot_Foward(BOT_HALF_SPEED, -BOT_HALF_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = Flatten;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case BackRightState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 150);
                Bot_Foward(-BOT_HALF_SPEED, BOT_HALF_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = Flatten;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Flatten: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 500);
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = TinyForward;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TinyForward: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 200);
                Bot_Foward(BOT_SIX_SPEED, BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = TurnState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case TurnState: //turn 90 degrees away from left side

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 850);
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_SIX_SPEED, -BOT_SIX_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = ForwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case ForwardState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 1500);
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
                } else if (Global_Side == RIGHT_SIDE) {
                    Bot_Foward(BOT_THIRD_SPEED, 76);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == BOTH_FRONT_TRIPPED || ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TinyBack;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TinyBack: // in the first state, replace this with correct names
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(BACKUP_TIMER, 200);
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                Global_Side = !Global_Side;
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_AVOIDING;
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
        RunAvoid_BackObject_SubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAvoid_BackObject_SubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}