#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "state.h"
#include "alarm.h"
#include "alarmMonitor.h"
#include "pressureSensor.h"
#include "mainAlgo.h"
void setup()
{
	STATE(A_INIT)
	();
	STATE(AM_TIMER_INIT)
	();
	STATE(PS_INIT)
	();
}
int main()
{
	setup();
	while (1)
	{
		pressureSensor_state();
		mainAlgo_state();
		alarmMonitor_state();
		alarm_state();
	}
}
