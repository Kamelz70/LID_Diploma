#include "pressureSensor.h"
// //////////////////////////////////////////
// Attributes
// //////////////////////////////////////////
vuint32 pVal;
const uint32 pollingPeriod = PSENSOR_POLLING_PERIOD;
// state declaration
void (*pressureSensor_state)();

// //////////////////////////////////////////
// Methods
// //////////////////////////////////////////
void sensor_init()
{
    // INITIALIZE PSENSOR
    GPIO_INITIALIZATION();
}

// //////////////////////////////////////////
// State functions' definitions
// //////////////////////////////////////////
STATE_DEFINE(PS_INIT)
{
    // set state
    pressureSensor_state_id = PS_INIT;
    sensor_init();
    // next state transition
    pressureSensor_state = STATE(PS_READING);
}

STATE_DEFINE(PS_READING)
{
    // SET STATE
    pressureSensor_state_id = PS_READING;
    // Get Pressure with drivers
    pVal = getPressureVal();
    // Send Pressure Value to main algorithm
    sendPressureVal(pVal);
    // next state transition
    pressureSensor_state = STATE(PS_WAITING);
}

STATE_DEFINE(PS_WAITING)
{
    // SET STATE
    pressureSensor_state_id = PS_WAITING;
    // Await timer
    // delay(pollingPeriod);
    delay(pollingPeriod * 100);
    // next state transition
    pressureSensor_state = STATE(PS_READING);
}
