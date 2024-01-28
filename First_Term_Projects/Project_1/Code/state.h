/*
 *Author:Mohamed Kamel
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"

// //////////////////////////////////////////
// State function factory
// //////////////////////////////////////////
#define STATE_DEFINE(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

// //////////////////////////////////////////
// State connections
// //////////////////////////////////////////
void send_pressure_val(int pVal);
void highPressureDetected();
void alarmOn();
void alarmOff();

#endif /* STATE_H_ */