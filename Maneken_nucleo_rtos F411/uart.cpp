#include "uart.h"

Serial pc(SERIAL_TX, SERIAL_RX);
uint8_t bufferUart[2];
uint8_t bufferUartCount=0;
int8_t flag_thread=0;

extern My_motor motor0;	//A,B,PWM
extern My_motor motor1;	//A,B,PWM
extern My_motor motor2;	//A,B,PWM
extern My_motor motor3;	//A,B,PWM
extern My_motor motor4;	//A,B,PWM
extern My_motor motor5;	//A,B,PWM
extern My_motor motor6;	//A,B,PWM
extern My_motor motor7;	//A,B,PWM

extern My_potentiometer pot0; //Pin, pot_min, pot_max, delta
extern My_potentiometer pot1;
extern My_potentiometer pot2; 
extern My_potentiometer pot3; //Pin, pot_min, pot_max, delta
extern My_potentiometer pot4;
extern My_potentiometer pot5; 
extern My_potentiometer pot6; //Pin, pot_min, pot_max, delta
extern My_potentiometer pot7;

void UartRX()
{
    bufferUart[bufferUartCount]=pc.getc();
		bufferUartCount++;
		
		if(bufferUartCount == 2)
		{
			ParseBuffer();
			
			bufferUartCount=0;
			bufferUart[0]=0;
			bufferUart[1]=0;
		}
		
}

void ParseBuffer()
{
	uint8_t number;
		
	if(bufferUart[0] == 0)
	{
		number = 0;
		
		ParseCommand(&motor0, &pot0, number);
	}
	else if(bufferUart[0] == 1)
	{
		number = 1;
		
		ParseCommand(&motor1, &pot1, number);
	}
	else if(bufferUart[0] == 2)
	{
		number = 2;
		
		ParseCommand(&motor2, &pot2, number);
	}
	else if(bufferUart[0] == 3)
	{
		number = 3;
		
		ParseCommand(&motor3, &pot3, number);
	}
	else if(bufferUart[0] == 4)
	{
		number = 4;
		
		ParseCommand(&motor4, &pot4, number);
	}
	else if(bufferUart[0] == 5)
	{
		number = 5;
		
		ParseCommand(&motor5, &pot5, number);
	}
	else if(bufferUart[0] == 6)
	{
		number = 6;
		
		ParseCommand(&motor6, &pot6, number);
	}
	else if(bufferUart[0] == 7)
	{
		number = 7;
		
		ParseCommand(&motor7, &pot7, number);
	}
	
	
	
    
}

void ParseCommand(My_motor *uartMotor, My_potentiometer *uartPot, uint8_t number)
{
	float test_speed=0.2;
	float wait_time=0.1;
	
	if(bufferUart[1] == 1)
	{
		uartMotor->SetSpeed(test_speed);
		uartMotor->SetDirection(1);
		wait(wait_time);
		uartMotor->Stop();  
	}
	else if(bufferUart[1] == 2)
	{
		uartMotor->SetSpeed(test_speed);
		uartMotor->SetDirection(2);
		wait(wait_time);
		uartMotor->Stop();  
	}
	else if(bufferUart[1] == 3)
	{
		pc.printf("pot%d=%f\r\n", number, uartPot->GetPosition());
	}
	else if(bufferUart[1] == 4)
	{
		flag_thread=number;
	}
	else if(bufferUart[1] == 5)
	{
		flag_thread=number+10;
	}
}
