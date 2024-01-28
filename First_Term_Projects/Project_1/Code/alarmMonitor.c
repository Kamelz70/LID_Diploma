#include "alarmMonitor.h"

// //////////////////////////////////////////
// Attributes
// //////////////////////////////////////////
const int alarmDuration = ALARM_DURATION;

// //////////////////////////////////////////
// state declaration
// //////////////////////////////////////////
void (*alarmMonitor_state)();

// //////////////////////////////////////////
// Methods
// //////////////////////////////////////////
void highPressureDetected()
{
    alarmMonitor_state_id = AM_ALARM_ON;
}

// //////////////////////////////////////////
// State functions' definitions
// //////////////////////////////////////////
STATE_DEFINE(AM_TIMER_INIT)
{
    // set state
    alarmMonitor_state_id = AM_TIMER_INIT;
    // initialize timers
    // next state transition
    alarmMonitor_state_id = STATE(AM_ALARM_OFF);
}

STATE_DEFINE(AM_ALARM_OFF)
{
    // set state
    alarmMonitor_state_id = AM_ALARM_OFF;
    // stop alarm
    alarmOff();
    // No state transition
}

STATE_DEFINE(AM_ALARM_ON)
{
    // start alarm
    alarmOn();
    // delay(alarmDuration);
    delay(alarmDuration * 100);
    // next state transition
    alarmMonitor_state_id = STATE(AM_ALARM_OFF);
}