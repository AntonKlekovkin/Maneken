#include "uart.h"

Serial kinnectUart(PA_15, PB_7);	//TX, RX
extern Serial pc;

DigitalOut photoPin(PD_2, 1);

DigitalIn phoneCatcher(PC_11, PullUp);
uint8_t phoneCatchFlag = 0;

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

uint8_t photoDone = 0;

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
	
	SetSpeedMotor(2.5, 2.5);
	
	//motor7.SetPosition(100-bufferKinnect[1]);
	motor1.SetPosition(bufferKinnect[2]);
	motor2.SetPosition(bufferKinnect[3]);
	motor3.SetPosition(bufferKinnect[5]);
	motor4.SetPosition(bufferKinnect[6]);
	motor5.SetPosition(100-bufferKinnect[7]);
	motor6.SetPosition(bufferKinnect[4]);			//head
}

void SoundThreadBody()
{
	static uint8_t timeThread = 0;
	uint8_t fileSound = 0;
	
	srand( time(0) );
	
	while(1)
	{
		if(timeThread == 10)
		{
			fileSound = rand() % 10;
			
			kinnectUart.putc(fileSound);
			pc.printf("Random phrase %d\r\n", fileSound);
			timeThread = 0;
		}
		
		if(phoneCatchFlag && !photoDone)
		{
			wait(0.1);
			if(phoneCatchFlag && !photoDone)
			{		
				kinnectUart.putc(25);
				pc.printf("Phone in my hand\r\n");
				PhotoStart();				
				timeThread = 0;
				photoDone = 1;
			}
		}
		
		if(phoneCatcher)
		{
			phoneCatchFlag = 0;
			photoDone = 0;
		}
		else
		{
			phoneCatchFlag = 1;
		}
		
		
		wait(1);
		timeThread++;
	}	
}


void PhotoStart()
{
	wait(5);
	
	kinnectUart.putc(20);
	pc.printf("Prepare, I'm going to take a picture in 3 seconds\r\n");
	wait(1);	
	Trajectory(0, 0, 0, 100, 0, 100, 0, 2.0, 2.0);
	
	kinnectUart.putc(23);
	pc.printf("Three\r\n");
	wait(1);
	
	kinnectUart.putc(22);
	pc.printf("Two\r\n");
	wait(1);
	
	kinnectUart.putc(21);
	pc.printf("One\r\n");
	wait(1);
	
	photoPin = 0;
	wait(0.1);
	photoPin = 1;
	
	wait(1);
	
	TrajectoryInterval();
	//Trajectory(0, 0, 0, 0, 0, 0, 0, 0.1, 0.1);
	
	
	kinnectUart.putc(24);
	pc.printf("Photo is ready\r\n");
	
	
}



