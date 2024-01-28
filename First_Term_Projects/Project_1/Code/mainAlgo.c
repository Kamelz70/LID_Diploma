#include "mainAlgo.h"
// //////////////////////////////////////////
// Attributes
// //////////////////////////////////////////
const uint32 threshold = PRESSURE_THRESHOLD;
int pVal = 0;

// //////////////////////////////////////////
// State declaration
// //////////////////////////////////////////
void (*mainAlgo_state)();

// //////////////////////////////////////////
// Methods
// //////////////////////////////////////////
void sendPressureVal(int pressure)
{
    pVal = pressure;
    mainAlgo_state = STATE(MA_CHECKING_PRESSURE);
}

// //////////////////////////////////////////
// State functions' definitions
// //////////////////////////////////////////
STATE_DEFINE(MA_CHECKING_PRESSURE)
{
    mainAlgo_state_id = MA_CHECKING_PRESSURE;
    // FIXME SUPPOSED TO RUN NOTHING
    if (pVal > threshold)
    {
        // Trigger Alarm Monitor
        highPressureDetected();
        mainAlgo_state = STATE(MA_CHECKING_PRESSURE);
    }
    else
    {
        mainAlgo_state = STATE(MA_CHECKING_PRESSURE);
    }
}