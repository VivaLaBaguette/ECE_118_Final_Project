#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "Avoid_Obstacle_Right_Sub.h"
#include "bot_Movement.h"

typedef enum {
    InitSubState,
    BackUpState,
    TurnState,
    ForwardState,
    BackUpState2,
    Turn90BackState,

} Avoid_Obstacle_RightSubHSMState_t;

static const char *StateNames[] = {
    "InitSubState",
    "BackUpState",
    "TurnState",
    "ForwardState",
    "BackUpState2",
    "Turn90BackState",
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
                ES_Timer_InitTimer(AVOID_TIMER, 200);
                nextState = BackUpState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;

            }
            break;

        case BackUpState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
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
                ES_Timer_InitTimer(AVOID_TIMER, 600);
                Bot_Foward(BOT_HALF_SPEED, -BOT_MAX_SPEED);
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
                Bot_Foward(BOT_LEFT_MAX_SPEED, BOT_MAX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == BOTH_FRONT_TRIPPED) {
                nextState = BackUpState2;
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
                Bot_Foward(-BOT_SIX_SPEED, -BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
            }
            if (ThisEvent.EventType == ES_TIMEOUT) { //so if towards is done and finished navigating, transition top level to shooting
                nextState = Turn90BackState;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                break;
            }
            if (ThisEvent.EventType == ES_NO_EVENT) {
                break;
            }
            break;

        case Turn90BackState: //go forward to goal

            if (ThisEvent.EventType == ES_ENTRY) {
                ES_Timer_InitTimer(AVOID_TIMER, 600);
                Bot_Foward(-BOT_SIX_SPEED, BOT_SIX_SPEED);
            }
            if (ThisEvent.EventType == ES_EXIT) {
                Bot_Stop();
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