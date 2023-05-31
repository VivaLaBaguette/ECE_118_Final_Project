
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"
#include "bot_Movement.h"

//sub state machines
//#include "Backwards_Sub.h"
//#include "Shooting_Sub.h"
//#include "Towards_Sub.h"
//#include "bot_Sensor.h"

#define DELAY(x)    for (unsigned int wait = 0; wait <= x; wait++) {asm("nop");}
#define delaymed  1830000

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

                // now put the machine into the actual initial state

                nextState = Reloading_State;
                makeTransition = TRUE;
                ThisEvent.EventType = ES_NO_EVENT;
                ;
            }
        case Reloading_State:
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        Bot_Foward(BOT_MAX_SPEED, -BOT_MAX_SPEED);
                        break;
                    case ES_EXIT:
                        Bot_Stop();
                        break;

                    case BACKLEFT_TRIPPED:
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


        case Drive_Towards_State: // in the first state, replace this with correct names
            if (ThisEvent.EventType != ES_NO_EVENT) {
                switch (ThisEvent.EventType) {
                    case ES_ENTRY:
                        Bot_Foward(BOT_MAX_SPEED, BOT_MAX_SPEED);
                        break;
                    case ES_EXIT:
                        Bot_Stop();
                        
                        break;

                    case FRONTRIGHT_TRIPPED:
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

void Bot_Foward(char RSpeed, char LSpeed) {
    Bot_Left_Motor(LSpeed);
    Bot_Right_Motor(RSpeed);
}

void Bot_Stop(void) {
    Bot_Left_Motor(0);
    Bot_Right_Motor(0);
}