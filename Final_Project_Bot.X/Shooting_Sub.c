
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Shooting_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitSubState,
    TurnTowardsWallState,
    FowardIntoWallState,
    RightWallState,
    LeftWallState,
    PressIntoState,
    BackUpState,
    FlywheelWaitState,
    TurnABit,
    Detect2State,
    AdjustLeft,
    AdjustRight,
    ShootState,

} ShootingSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "TurnTowardsWallState",
    "FowardIntoWallState",
    "RightWallState",
    "LeftWallState",
    "PressIntoState",
    "BackUpState",
    "FlywheelWaitState",
    "TurnABit",
    "Detect2State",
    "AdjustLeft",
    "AdjustRight",
    "ShootState",
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
                ES_Timer_InitTimer(SHOOTING_TIMER, 600);
                nextState = TurnTowardsWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;

        case TurnTowardsWallState: // in the first state, replace this with correct names

            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
                } else {
                    Bot_Foward(BOT_SIX_SPEED, -BOT_SIX_SPEED);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = FowardIntoWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case FowardIntoWallState:
            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                //                ES_Timer_InitTimer(SHOOTING_TIMER, 150);

            }
            if (ThisEvent.EventType == FRONTLEFT_TRIPPED) {
                nextState = LeftWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == FRONTRIGHT_TRIPPED) {
                nextState = RightWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BOTH_FRONT_TRIPPED) {
                nextState = PressIntoState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case LeftWallState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 200);
                Bot_Foward(-BOT_THIRD_SPEED, BOT_HALF_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = PressIntoState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case RightWallState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 200);
                Bot_Foward(BOT_HALF_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FRONTLEFT_TRIPPED || ThisEvent.EventType == BOTH_FRONT_TRIPPED) {
                nextState = PressIntoState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
        case PressIntoState: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 500);
                Bot_Foward(BOT_HALF_SPEED, BOT_HALF_SPEED);
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
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 400);
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
                Bot_Flywheel(BOT_FLYWHEEL_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = FlywheelWaitState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case FlywheelWaitState:
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 300);
            }
            if (ThisEvent.EventType == ES_EXIT) {
            }
            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = Detect2State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Detect2State: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                if (Global_Side == LEFT_SIDE) {
                    Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
                } else {
                    Bot_Foward(-BOT_THIRD_SPEED, BOT_THIRD_SPEED);
                }
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == DETECTED_CLOSE_2KHZ) {
                if (Global_Side == LEFT_SIDE) {
                    nextState = AdjustLeft;
                } else {
                    nextState = AdjustRight;
                }

                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AdjustLeft: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 130); //try 130 if it doesnt work
                Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
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

        case AdjustRight: // in the first state, replace this with correct names
            //think about timing here
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(SHOOTING_TIMER, 200);
                Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
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
                Bot_Loader(BOT_LOADER_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                Bot_Flywheel(0);
                Bot_Loader(0);
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