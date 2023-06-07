#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Towards_Sub.h"
#include "Acquire_Sub.h"
#include "Drive_Foward_Sub.h"
#include "bot_Movement.h"
#include "Positioning_Left_Sub.h"
#include "Positioning_Right_Sub.h"
#include "Avoid_Obstacle_Sub.h"

#include <stdio.h>

typedef enum {
    InitSubState,
    AcquireBeaconState,
    PositionState,
    DriveFowardState,
    AvoidRightWallState,
    AvoidLeftWallState,
    TankTurnLeft,
    TankTurnRight,
    AvoidObstacleState,

} TowardsSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "AcquireBeaconState",
    "PositionState",
    "DriveFowardState",
    "AvoidRightWallState",
    "AvoidLeftWallState",
    "TankTurnLeft",
    "TankTurnRight",

    "AvoidObstacleState",
};

static TowardsSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitTowardsSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunTowardsSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunTowardsSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    TowardsSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                InitAcquireSubHSM();
                //NEED TO MAKE A RIGHT AND AND A LEFT DRIVE POSITION SUB STATE
                InitDriveFowardSubHSM();


                nextState = AcquireBeaconState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
            }
            break;


        case AcquireBeaconState: // in the first state, replace this with correct names
            ThisEvent = RunAcquireSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }
            if (ThisEvent.EventType == ES_EXIT) {
                if (Global_Side == LEFT_SIDE) {
                    InitPositioningLeftSubHSM();
                } else if (Global_Side == RIGHT_SIDE) {
                    InitPositioningRightSubHSM();
                }
                Bot_Stop();
            }
            if (ThisEvent.EventType == ACQUIRED_2KHZ) {

                nextState = PositionState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case PositionState: //back up until both back bumpers are tripped
            if (Global_Side == LEFT_SIDE) {
                ThisEvent = RunPositioningLeftSubHSM(ThisEvent);
            } else if (Global_Side == RIGHT_SIDE) {
                ThisEvent = RunPositioningRightSubHSM(ThisEvent);
            }

            if (ThisEvent.EventType == ES_ENTRY) {
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            //once both bumpers are tripped, continue back with blocking code for just a bit
            if (ThisEvent.EventType == FINISHED_POSITIONING) {
                //then drive foward
                nextState = DriveFowardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case DriveFowardState: //go forward to goal
            ThisEvent = RunDriveFowardSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }

            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == FRONTLEFT_TRIPPED && Global_Side == LEFT_SIDE) {
                nextState = AvoidLeftWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == FRONTRIGHT_TRIPPED && Global_Side == RIGHT_SIDE) {
                nextState = AvoidRightWallState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if ((ThisEvent.EventType == FRONTRIGHT_TRIPPED || ThisEvent.EventType == BOTH_FRONT_TRIPPED) && Global_Side == LEFT_SIDE) {
                InitAvoid_Obstacle_SubHSM();
                nextState = AvoidObstacleState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if ((ThisEvent.EventType == FRONTLEFT_TRIPPED || ThisEvent.EventType == BOTH_FRONT_TRIPPED) && Global_Side == RIGHT_SIDE) {
                InitAvoid_Obstacle_SubHSM();
                nextState = AvoidObstacleState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }

            if (ThisEvent.EventType == FINISHED_NAVIGATION) { //so if towards is done and finished navigating, transition top level to shooting
                makeTransition = FALSE;
                ThisEvent.EventType = FINISHED_NAVIGATION;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;


        case AvoidLeftWallState: //back up until both back bumpers are tripped
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 700);
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TankTurnLeft;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;
            
        case TankTurnLeft: //back up until both back bumpers are tripped
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 150);
                Bot_Foward(BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = DriveFowardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AvoidRightWallState: //back up until both back bumpers are tripped
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 700);
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = TankTurnRight;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TankTurnRight: //back up until both back bumpers are tripped
            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 150);
                Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }

            if (ThisEvent.EventType == ES_TIMEOUT) {
                nextState = DriveFowardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

            ///DO THIS CASE LATER, FOR AVOIDING OBSTACLES
        case AvoidObstacleState:
            
            ThisEvent = RunAvoid_Obstacle_SubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }

            if (ThisEvent.EventType == ES_EXIT) {
                InitTowardsSubHSM();
            }

            if (ThisEvent.EventType == FINISHED_AVOIDING) {
                nextState = AcquireBeaconState;
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
        RunTowardsSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunTowardsSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}