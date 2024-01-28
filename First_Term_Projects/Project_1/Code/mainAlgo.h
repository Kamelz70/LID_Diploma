// Author: Mohamed Kamel

#ifndef MAIN_ALGO_H_
#define MAIN_ALGO_H_
#include "state.h"
#include "platform_types.h"
#include "driver.h"

// //////////////////////////////////////////
// States
// //////////////////////////////////////////
enum
{
	MA_CHECKING_PRESSURE,
} mainAlgo_state_id;

// //////////////////////////////////////////
// Export State
// //////////////////////////////////////////
extern void (*mainAlgo_state)();

// //////////////////////////////////////////
// Protoypes
// //////////////////////////////////////////
STATE_DEFINE(MA_CHECKING_PRESSURE);
void sendPressureVal(int pressure);

// //////////////////////////////////////////
// Configuration
// //////////////////////////////////////////
#define PRESSURE_THRESHOLD 20

#endif /* MAIN_ALGO_H_ */