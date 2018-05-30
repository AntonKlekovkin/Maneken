#include "distanceSensor.h"

#define POWER_3_3 
//#define POWER_5		

static AnalogIn distanceSensor(PC_2);

//static DigitalOut trig(PC_2);
//static DigitalIn echo(PC_3);

float currentDistance;

void RefreshDistance()
{
	float an;
	
	an = distanceSensor.read();
	
	#ifdef POWER_5
	currentDistance = (an * 0.2592f) / 0.00030303f;
	#endif
	#ifdef POWER_3_3
	currentDistance = (an * 0.396875f) / 0.00030303f;
	#endif
}


