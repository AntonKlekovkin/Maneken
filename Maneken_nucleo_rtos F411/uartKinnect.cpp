#include "uart.h"

#define MOVING_ACTIVATE	0

Serial kinnectUart(PA_15, PB_7);	//TX, RX
extern Serial pc;
extern float currentDistance;

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
	
	srand( time(0) );
	
	while(1)
	{
		if(CheckCurrentDistance(100, 1500))
		{
			if (rand() % 2)
			{
				kinnectUart.putc(14);	//дзеч буреч
				pc.printf("Dzech burech\r\n");
				wait(3);
			}
			else
			{
				kinnectUart.putc(28);	//привет отлично выглядишь
				pc.printf("Hello, you look great\r\n");
				wait(3);
			}
			
			kinnectUart.putc(17);	// давай сфотографируемся
			pc.printf("Let's take a picture\r\n");
			wait(2);
			kinnectUart.putc(16);	// встань на линию
			pc.printf("Go to line, I'm going to take a picture\r\n");
			wait(5);
			
			for(int i = 0; i < 2; i++)
			{
				if(CheckCurrentDistance(160, 500) )
				{
					kinnectUart.putc(26);	// отойди чуть дальше
					pc.printf("Go a little\r\n");
					wait(5);
				}
			}
			
			for(int i = 0; i < 3; i++)
			{
				if( CheckCurrentDistance(180, 250, 500) )
				{
					if (rand() % 2)
					{
						kinnectUart.putc(34);
						pc.printf("Smile\r\n");
						wait(1);
					}
					else
					{
						kinnectUart.putc(32);
						pc.printf("Cheese\r\n");
						wait(1);
					}
					
					PhotoStart();
					
					kinnectUart.putc(35);
					pc.printf("Photo in group in VK\r\n");
					wait(5);
					break;
				}
				wait(1);
			}
			
			if (rand() % 2)
			{
				kinnectUart.putc(31);
				pc.printf("Shapka\r\n");
				wait(4);
			}
			else
			{
				kinnectUart.putc(15);
				pc.printf("And now look at my clothes\r\n");
				wait(3);
			}
			
			kinnectUart.putc(27);
			pc.printf("Last fashion peep\r\n");
			wait(2);
			
			#if MOVING_ACTIVATE
			Trajectory4();
			#endif
			
			kinnectUart.putc(30);
			pc.printf("Sellers give you right size\r\n");
			wait(2);
			
			#if MOVING_ACTIVATE
			TrajectoryToSellers();
			#endif
			
			wait(5);
		}
		
	}	
}



void PhotoStart()
{
	//wait(5);
	
	kinnectUart.putc(20);
	pc.printf("Prepare, I'm going to take a picture in 3 seconds\r\n");
	wait(4);	
	
	#if MOVING_ACTIVATE
	Trajectory(-1, -1, -1, 100, -1, 100, -1, 2.0, 2.0);
	#endif
	
	kinnectUart.putc(21);
	pc.printf("One\r\n");
	wait(1);
	
	kinnectUart.putc(22);
	pc.printf("Two\r\n");
	wait(1);
	
	kinnectUart.putc(23);
	pc.printf("Three\r\n");
	wait(1);
	
	
	TakePicture();
	wait(0.5);
	TakePicture();
	
	
	wait(1);
	
	#if MOVING_ACTIVATE
	TrajectoryInterval();
	#endif
	
		
	kinnectUart.putc(24);
	pc.printf("Photo is ready\r\n");
	wait(2);
	
}

void TakePicture()
{
	photoPin = 0;
	wait(0.1);
	photoPin = 1;
}

bool CheckCurrentDistance(uint16_t dis, uint16_t t)
{
	if(currentDistance < dis)
	{
		wait_ms(t);
		
		if(currentDistance < dis)
		{
			return true;
		}
	}
	
	return false;
}

bool CheckCurrentDistance(uint16_t dis1, uint16_t dis2, uint16_t t)
{
	if(currentDistance < dis2 && currentDistance > dis1)
	{
		wait_ms(t);
		
		if(currentDistance < dis2 && currentDistance > dis1)
		{
			return true;
		}
	}
	
	return false;
}

