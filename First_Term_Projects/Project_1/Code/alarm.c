#include "alarm.h"
// NoAttributes

// //////////////////////////////////////////
// state declaration
// //////////////////////////////////////////
void (*alarm_state)();

// //////////////////////////////////////////
// Methods
// //////////////////////////////////////////
void alarmOn()
{
    alarm_state = STATE(A_ALARM_ON);
}
void alarmOff()
{
    alarm_state = STATE(A_ALARM_OFF);
}

// //////////////////////////////////////////
// State functions' definitions
// //////////////////////////////////////////
STATE_DEFINE(A_INIT)
{
    // set state
    alarm_state_id = A_INIT;
    // init GPIO
    GPIO_INITIALIZATION();
    // init alarm WITH 0
    Set_Alarm_actuator(1);
    // set first state
    alarm_state = STATE(A_WAITING);
}
STATE_DEFINE(A_ALARM_ON)
{
    // set state
    alarm_state_id = A_ALARM_ON;
    // set alarm
    Set_Alarm_actuator(0);
    // next state transition
    alarm_state = STATE(A_WAITING);
}
STATE_DEFINE(A_ALARM_OFF)
{
    // set state
    alarm_state_id = A_ALARM_OFF;
    // set alarm
    Set_Alarm_actuator(1);
    // next state transition
    alarm_state = STATE(A_WAITING);
}

STATE_DEFINE(A_WAITING)
{
    // set state
    alarm_state_id = A_WAITING;
    // No state transition
}
