// Author: Mohamed Kamel
#ifndef PRESSURE_SENSOR_H
#define PRESSURE_SENSOR_H

#include "state.h"
#include "driver.h"
#include "platform_types.h"
// //////////////////////////////////////////
// States
// //////////////////////////////////////////
enum
{
    PS_INIT,
    PS_READING,
    PS_WAITING,
} pressureSensor_state_id;

// //////////////////////////////////////////
// Export state
// //////////////////////////////////////////
extern void (*pressureSensor_state)(void);

// //////////////////////////////////////////
// Protoypes
// //////////////////////////////////////////

STATE_DEFINE(PS_INIT);
STATE_DEFINE(PS_WAITING);
STATE_DEFINE(PS_READING);

// //////////////////////////////////////////
// Configuration
// //////////////////////////////////////////
#define PSENSOR_POLLING_PERIOD 100

#endif
