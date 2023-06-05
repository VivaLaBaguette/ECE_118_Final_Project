#include "bot_Sensor.h"

#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "bot_Movement.h"
#include "Towards_Sub.h"
#include "Shooting_Sub.h"

#include <stdio.h>

//sub state machines
//#include "Backwards_Sub.h"
//#include "Shooting_Sub.h"
//#include "Towards_Sub.h"
//#include "bot_Sensor.h"

typedef enum {
    Init_State,
    Reloading_State,
    Drive_Towards_State,
    Shooting_State,
    Drive_Backwards_State,
} HSMState_t;

static const char *StateNames[] = {
    "Init_State",
    "Reloading_State",
    "Drive_Towards_State",
    "Shooting_State",
    "Drive_Backwards_State",
};



static HSMState_t CurrentState = Init_State; // <- change enum name to match ENUM
static uint8_t MyPriority;

uint8_t InitHSM(uint8_t Priority) {
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = Init_State;
    Global_Side = Bot_Side();
    Original_Side = Global_Side;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostHSM(ES_Event ThisEvent) {
    return ES_PostToService(MyPriority, ThisEvent);
}

ES_Event RunHSM(ES_Event ThisEvent) {
    uint8_t makeTransition = FALSE; // use to flag transition
    HSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
        case Init_State:
            if (ThisEvent.EventType == ES_INIT) {
                // Initialize all sub-state machines
                //                InitSubHSM();
                //ADD MORE SUB STATE MACHINES!!!!!!!!!!!!!!!!!!!!


                // now put the machine into the actual initial state
                nextState = Reloading_State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                ;
            }

            //RELOADING STATE JUST WAITS FOR TIMER AND MOVES ON

        case Reloading_State:
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        //start timer
                        ES_Timer_InitTimer(RELOADING_TIMER, TIMER_RELOAD_TICK);
                        Bot_Stop();

                        break;

                    case ES_EXIT: //when exiting the state, stop
                        InitTowardsSubHSM();
                        Bot_Stop();
                        break;

                    case ES_TIMEOUT: //timeout, go to drive towrads state
                        nextState = Drive_Towards_State;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_NO_EVENT:
                    default:
                        break;
                }
            }
            break;

            //DRIVE TOWARDS SUB STATE MACHINE
        case Drive_Towards_State:

            ThisEvent = RunTowardsSubHSM(ThisEvent);

            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        printf("\r\nDriving the thing \r\n");
                        break;
                    case ES_EXIT:
                        Bot_Stop();
                        InitShootingSubHSM();
                        break;
                    case FINISHED_NAVIGATION:
                        nextState = Shooting_State;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_NO_EVENT:
                    default:
                        break;
                }
            }

            break;

        case Shooting_State:

            ThisEvent = RunShootingSubHSM(ThisEvent);

            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        printf("Shooting the thing");
                        break;
                    case ES_EXIT:
                        Bot_Stop();
                        break;

                    case FINISHED_SHOOTING: // change to finshed shooting or smthing
                        nextState = Drive_Backwards_State;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_NO_EVENT:
                    default:
                        break;
                }
            }

            break;

        case Drive_Backwards_State:

            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        printf("Doing the backwards the thing");
                        Bot_Foward(-BOT_MAX_SPEED, -BOT_MAX_SPEED);
                        break;

                    case ES_EXIT:
                        Bot_Stop();
                        break;

//                    case BACKLEFT_TRIPPED:
//                        nextState = Reloading_State;
//                        makeTransition = TRUE;
//                        ThisEvent.EventType = ES_NO_EVENT;
//                        break;
//
//                    case BACKRIGHT_TRIPPED:
//                        nextState = Reloading_State;
//                        makeTransition = TRUE;
//                        ThisEvent.EventType = ES_NO_EVENT;
//                        break;

                    case BOTH_REAR_TRIPPED:
                        nextState = Reloading_State;
                        makeTransition = TRUE;
                        ThisEvent.EventType = ES_NO_EVENT;
                        break;

                    case ES_NO_EVENT:
                    default:
                        break;
                }
            }

            break;



        default: // all unhandled states fall into here
            break;
    } // end switch on Current State


    if (makeTransition == TRUE) { // making a state transition, send EXIT and ENTRY
        // recursively call the current state with an exit event
        RunHSM(EXIT_EVENT); // <- rename to your own Run function
        CurrentState = nextState;
        RunHSM(ENTRY_EVENT); // <- rename to your own Run function
    }

    ES_Tail(); // trace call stack end
    return ThisEvent;
}

void Bot_Foward(char LSpeed, char RSpeed) {
    Bot_Left_Motor(LSpeed);
    Bot_Right_Motor(RSpeed);
}

void Bot_Stop(void) {
    Bot_Left_Motor(0);
    Bot_Right_Motor(0);
}