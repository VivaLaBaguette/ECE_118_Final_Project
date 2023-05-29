
#include "ES_Configure.h"
#include "ES_Framework.h"
#include "BOARD.h"
#include "HSM.h"

//sub state machines
#include "Backwards_Sub.h"
#include "Shooting_Sub.h"
#include "Towards_Sub.h"

typedef enum {
    Reloading_State,
	Drive_Towards_State,
	Shooting_State,
	Drive_Backwards_State,
} HSMState_t;

static const char *StateNames[] = {
	"InitPState",
	"FirstState",
};



static HSMState_t CurrentState = Reloading_State; // <- change enum name to match ENUM
static uint8_t MyPriority;


uint8_t InitHSM(uint8_t Priority)
{
    MyPriority = Priority;
    // put us into the Initial PseudoState
    CurrentState = Reloading_State;
    // post the initial transition event
    if (ES_PostToService(MyPriority, INIT_EVENT) == TRUE) {
        return TRUE;
    } else {
        return FALSE;
    }
}

uint8_t PostHSM(ES_Event ThisEvent)
{
    return ES_PostToService(MyPriority, ThisEvent);
}



ES_Event RunHSM(ES_Event ThisEvent)
{
    uint8_t makeTransition = FALSE; // use to flag transition
    HSMState_t nextState; // <- change type to correct enum

    ES_Tattle(); // trace call stack

    switch (CurrentState) {
    case Reloading_State: // If current state is initial Pseudo State
        if (ThisEvent.EventType == ES_INIT)// only respond to ES_Init
        {
            // this is where you would put any actions associated with the
            // transition from the initial pseudo-state into the actual
            // initial state
            // Initialize all sub-state machines
            InitSubHSM();
            // now put the machine into the actual initial state
            nextState = FirstState;
            makeTransition = TRUE;
            ThisEvent.EventType = ES_NO_EVENT;
            ;
        }
        break;



    case Drive_Towards_State: // in the first state, replace this with correct names
        // run sub-state machine for this state
        //NOTE: the SubState Machine runs and responds to events before anything in the this
        //state machine does
        ThisEvent = RunSubHSM(ThisEvent);
        switch (ThisEvent.EventType) {
        case ES_NO_EVENT:
        default:
            break;
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
