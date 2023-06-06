#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Avoid_Obstacle_Right_Sub.h"
#include "bot_Movement.h"
#include "BackwardsRight_Sub.h"

typedef enum {
    InitSubState,
    BackUpState,
    TinyForwardState,
    TurnState,
    AvoidRightState,
    ForwardState,
    BackUpState2,
    Turn90BackState,
    AcquireState,
    TurnBackState,
    TinyBackupState,
} Avoid_Obstacle_RightSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUpState",
    "TinyForwardState",
    "TurnState",
    "AvoidRightState",
    "ForwardState",
    "BackUpState2",
    "Turn90BackState",
    "AcquireState",
    "TurnBackState",
    "TinyBackupState",
};

static Avoid_Obstacle_RightSubHSMState_t CurrentState = InitSubState; // <- change name to match ENUM
static uint8_t MyPriority;

uint8_t InitAvoid_Obstacle_RightSubHSM(void) {
    ES_Event returnEvent;

    CurrentState = InitSubState;
    returnEvent = RunAvoid_Obstacle_RightSubHSM(INIT_EVENT);
    if (returnEvent.EventType == ES_NO_EVENT) {
        return TRUE;
    }
    return FALSE;
}

ES_Event RunAvoid_Obstacle_RightSubHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    Avoid_Obstacle_RightSubHSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case InitSubState: // If current state is initial Psedudo State
            if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
            {
                InitBackwardsRightSubHSM();
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

            }
            break;

        case BackUpState: //go forward to goal
            ThisEvent = RunBackwardsRightSubHSM(ThisEvent);

            if (ThisEvent.EventType == ES_ENTRY) {
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FINISHED_BACKWARDS) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = TinyForwardState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TinyForwardState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 200);
                Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
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
                ES_Timer_InitTimer(AVOID_TIMER, 450);
                Bot_Foward(-BOT_THIRD_SPEED, BOT_MAX_SPEED);
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
                Bot_Foward(BOT_THIRD_SPEED, BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == FRONTLEFT_TRIPPED) {
                nextState = AvoidLeftState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == BOTH_FRONT_TRIPPED || ThisEvent.EventType == FRONTRIGHT_TRIPPED) {
                nextState = BackUpState2;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AvoidLeftState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(POSITIONING_TIMER, 250);
                Bot_Foward(-BOT_HALF_SPEED, -BOT_THIRD_SPEED);
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

        case BackUpState2: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 200);
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();

            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = AcquireState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case AcquireState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == DETECTED_2KHZ) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = TurnBackState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TurnBackState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 100);
//                Bot_Foward(BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = TinyBackupState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case TinyBackupState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 300);
                Bot_Foward(-BOT_THIRD_SPEED, -BOT_THIRD_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
                Global_Side = RIGHT_SIDE;
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
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
        RunAvoid_Obstacle_RightSubHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunAvoid_Obstacle_RightSubHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end


    return ThisEvent;
}