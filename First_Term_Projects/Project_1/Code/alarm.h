// Author Mohamed Kamel
#ifndef ALARM_H
#define ALARM_H

#include "state.h"
#include "driver.h"
#include "platform_types.h"
// //////////////////////////////////////////
// States
// //////////////////////////////////////////
enum
{
    A_ALARM_ON,
    A_ALARM_OFF,
    A_INIT,
    A_WAITING,
} alarm_state_id;

// //////////////////////////////////////////
// export state
// //////////////////////////////////////////
extern void (*alarm_state)(void);

// //////////////////////////////////////////
// Prototypes
// //////////////////////////////////////////
STATE_DEFINE(A_INIT);
STATE_DEFINE(A_WAITING);
STATE_DEFINE(A_ALARM_ON);
STATE_DEFINE(A_ALARM_OFF);
void alarmOn();
void alarmOff();

#endif /*ALARM_H*/
