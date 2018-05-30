#include "distanceSensor.h"

#define POWER_3_3 
//#define POWER_5		

static AnalogIn distanceSensor(PC_4);

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

void ThreadDistanceSensor()
{
//	uint16_t timeDistanceSensor = 0;	
//	
//	while(1)
//	{
//		
//		trig = 0;
//		wait_us(2);
//		
//		trig = 1;
//		wait_us(10);
//		trig = 0;
//		
//		while(echo != 1);
//		
//		while(echo != 0)
//		{
//			wait_us(1);
//			timeDistanceSensor++;
//		}
//		
//		GetDistance(timeDistanceSensor);
//		timeDistanceSensor = 0;
//		
//		wait_ms(100);
//	}
	
}


void GetDistance(uint16_t t)
{
	//currentDistance = (float)t/58.0f;
	
}
