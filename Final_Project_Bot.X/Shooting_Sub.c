
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Shooting_Sub.h"
#include "bot_Movement.h"
#include "Acquire_Sub.h"

typedef enum {
    InitSubState,
    Acquire2State,
    TurnSlightlyLeftState,
    TurnSlightlyRightState,
    ShootState,
    TurnBackState,
} ShootingSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "Acquire2State",
    "TurnSlightlyState",
    "ShootState",
    "TurnBackState",
};

static ShootingSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitShootingSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunShootingSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunShootingSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    ShootingSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {

                nextState = Acquire2State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case Acquire2State: // in the first state, replace this with correct names

            ThisEvent = RunAcquireSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {

            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                ES_Timer_InitTimer(SHOOTING_TIMERTWOO, TIMER_SHOOT_POSITIONING_TICK);
            }
            if (ThisEvent.EventType == ACQUIRED_2KHZ) {
                if (Global_Side == LEFT_SIDE) {
                    nextState = TurnSlightlyLeftState; //change bCK TO TUR SLIHTLY
                } else {
                    nextState = TurnSlightlyRightState;
                }
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TurnSlightlyLeftState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-BOT_THIRD_SPEED, BOT_THIRD_SPEED);
                Bot_Flywheel(BOT_SLOW_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = ShootState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TurnSlightlyRightState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                Bot_Flywheel(BOT_SLOW_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = ShootState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case ShootState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, TIMER_SHOOTING_TICK);
                Bot_Loader(BOT_MAX_SPEED);
                Bot_Flywheel(BOT_SLOW_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                Bot_Flywheel(0);
                Bot_Loader(0);
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TurnBackState;
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_SHOOTING;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TurnBackState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMERTWOO, TIMER_SHOOT_POSITIONING_TICK);
                
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                } else {
                    Bot_Foward(-BOT_THIRD_SPEED, BOT_THIRD_SPEED);
                }
            }
            
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_SHOOTING;
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
        RunShootingSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunShootingSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}