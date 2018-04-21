#include "motors_threads.h"


// for motor
My_motor motor0(PB_13, PB_14, PA_10);	//A,B,PWM
My_motor motor1(PB_15, PB_1, PB_3);	//A,B,PWM
My_motor motor2(PB_2, PB_12, PB_5);	//A,B,PWM
My_motor motor3(PA_11, PA_12, PB_4);	//A,B,PWM
My_motor motor4(PC_5, PC_6, PB_10);	//A,B,PWM
My_motor motor5(PB_6, PA_7, PA_8);	//A,B,PWM
My_motor motor6(PA_6, PA_5, PA_9);	//A,B,PWM
My_motor motor7(PB_9, PB_8, PC_7);	//A,B,PWM

My_potentiometer pot0(PC_0, 0.28, 0.64, 0.02); //Pin, pot_min, pot_max, delta
My_potentiometer pot1(PC_1, 0.71, 0.91, 0.02);
My_potentiometer pot2(PB_0, 0.28, 0.64, 0.02); 
My_potentiometer pot3(PA_4, 0.00, 0.15, 0.02);
My_potentiometer pot4(PA_1, 0.28, 0.64, 0.02); 
My_potentiometer pot5(PA_0, 0.35, 0.67, 0.02);
My_potentiometer pot6(PC_3, 0.28, 0.64, 0.02); 
My_potentiometer pot7(PC_2, 0.74, 0.98, 0.02);

void motor0_body()
{
	
	motor0.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{ 
		motor0.Pid.SetSettedValue(140);
		motor0.SetDirection(2);
		while( !pot0.IsMinValue() );
		motor0.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		motor0.Pid.SetSettedValue(140);
		motor0.SetDirection(1);
		while( !pot0.IsMaxValue() );
		motor0.Stop();
		wait(0.5);        
	}
}

void motor1_body()
{
	
	while (1) 
	{ 
		//down
		motor1.Pid.SetAllCoeff(0.1, 0.5, 0);

		motor1.Pid.SetSettedValue(pot1.min);
		motor1.SetDirection(2);
		while( !pot1.IsMinValue() );
		motor1.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		//up
		motor1.Pid.SetAllCoeff(2.0, 2.0, 0);
		
		motor1.Pid.SetSettedValue(pot1.max);
		motor1.SetDirection(1);
		while( !pot1.IsMaxValue() );
		motor1.Stop();
		wait(0.5);        
	}
}

void motor2_body()
{
	
	motor2.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{ 

		motor2.Pid.SetSettedValue(140);
		motor2.SetDirection(2);
		while( !pot2.IsMinValue() );
		motor2.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);

		motor2.Pid.SetSettedValue(140);
		motor2.SetDirection(1);
		while( !pot2.IsMaxValue() );
		motor2.Stop();
		wait(0.5);        
	}
}

void motor3_body()
{
	
	while (1) 
	{ 
		//up
		motor3.Pid.SetAllCoeff(5.0, 7.0, 0);
				
		motor3.Pid.SetSettedValue(pot3.min);
		motor3.SetDirection(2);
		while( !pot3.IsMinValue() );
		motor3.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		//down
		motor3.Pid.SetAllCoeff(1.3, 7.0, 0);
		
		motor3.Pid.SetSettedValue(pot3.max);
		motor3.SetDirection(1);
		while( !pot3.IsMaxValue() );
		motor3.Stop();
		wait(0.5);        
	}
}

void motor4_body()
{
	
	motor4.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{ 
		motor4.Pid.SetSettedValue(140);
		motor4.SetDirection(2);
		while( !pot4.IsMinValue() );
		motor4.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		motor4.Pid.SetSettedValue(140);
		motor4.SetDirection(1);
		while( !pot4.IsMaxValue() );
		motor4.Stop();
		wait(0.5);        
	}
}

void motor5_body()
{
	
	
	
	while (1) 
	{
		//down
		motor5.Pid.SetAllCoeff(1.3, 5.0, 0);
		
		motor5.Pid.SetSettedValue(pot5.min);
		motor5.SetDirection(2);
		while( !pot5.IsMinValue() );
		motor5.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		//up
		motor5.Pid.SetAllCoeff(3.0, 5.0, 0);
		
		motor5.Pid.SetSettedValue(pot5.max);
		motor5.SetDirection(1);
		while( !pot5.IsMaxValue() );
		motor5.Stop();
		wait(0.5);        
	}
}

void motor6_body()
{
	
	motor6.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{
		motor6.Pid.SetSettedValue(140);
		motor6.SetDirection(2);
		while( !pot6.IsMinValue() );
		motor6.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		motor6.Pid.SetSettedValue(140);
		motor6.SetDirection(1);
		while( !pot6.IsMaxValue() );
		motor6.Stop();
		wait(0.5);        
	}
}

void motor7_body()
{
	
	motor7.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{
		motor7.Pid.SetSettedValue(140);
		motor7.SetDirection(2);
		while( !pot7.IsMinValue() );
		motor7.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		motor7.Pid.SetSettedValue(140);
		motor7.SetDirection(1);
		while( !pot7.IsMaxValue() );
		motor7.Stop();
		wait(0.5);        
	}
}

