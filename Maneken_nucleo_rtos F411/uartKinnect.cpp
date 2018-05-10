#include "uart.h"

Serial kinnectUart(PA_15, PB_7);	//TX, RX

extern My_motor motor0;	//A,B,PWM
extern My_motor motor1;	//A,B,PWM
extern My_motor motor2;	//A,B,PWM
extern My_motor motor3;	//A,B,PWM
extern My_motor motor4;	//A,B,PWM
extern My_motor motor5;	//A,B,PWM
extern My_motor motor6;	//A,B,PWM
extern My_motor motor7;	//A,B,PWM

const uint8_t bufferKinnectNumbers = 20;
uint8_t bufferKinnectCount = 0;
uint8_t bufferKinnect[bufferKinnectNumbers];

uint8_t flagBufferKinnect = 0;



void InitUartKinnect()
{
	
	kinnectUart.baud(115200);
  kinnectUart.attach(&KinnectUartInterrupt);
    
}

void KinnectUartInterrupt()
{
	uint8_t temp = kinnectUart.getc();
	static uint8_t flagBufferStart=0;
	
	
	if(temp == 127)
	{
		bufferKinnectCount = 0;
		bufferKinnect[bufferKinnectCount]=temp;
		flagBufferStart = 1;
	}
	
	if(flagBufferStart == 1)
	{
		if(temp != '~')
		{		
			if(bufferKinnectCount<bufferKinnectNumbers)
			{
				bufferKinnect[bufferKinnectCount]=temp;
				bufferKinnectCount++;
			}
			else
			{
				bufferKinnectCount=0;
			}
		}
		else
		{
			bufferKinnect[bufferKinnectCount]=temp;
			bufferKinnectCount=0;
			
			flagBufferKinnect = 1;
			flagBufferStart = 0;
			ParseBufferKinnect();
		}
	}
}

void ParseBufferKinnect()
{
	for(int i=1; i <= 7; i++)
	{
		if(bufferKinnect[i] > 100)
		{
			return;
		}
	}	
	
	//motor7.SetPosition(100-bufferKinnect[1]);
	motor1.SetPosition(bufferKinnect[2]);
	motor2.SetPosition(bufferKinnect[3]);
	motor3.SetPosition(bufferKinnect[5]);
	motor4.SetPosition(bufferKinnect[6]);
	motor5.SetPosition(100-bufferKinnect[7]);
	motor6.SetPosition(bufferKinnect[4]);			//head
}
