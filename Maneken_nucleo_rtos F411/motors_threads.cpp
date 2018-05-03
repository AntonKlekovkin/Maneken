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

My_potentiometer pot0(PC_0, 0.48, 0.82, 0.03); //Pin, pot_min, pot_max, delta
My_potentiometer pot1(PC_1, 0.71, 0.91, 0.03);
My_potentiometer pot2(PB_0, 0.55, 0.88, 0.03); 
My_potentiometer pot3(PA_4, 0.00, 0.17, 0.03);
My_potentiometer pot4(PA_1, 0.54, 0.74, 0.03); 
My_potentiometer pot5(PA_0, 0.35, 0.67, 0.03);
My_potentiometer pot6(PC_3, 0.70, 1.00, 0.03); 
My_potentiometer pot7(PC_2, 0.74, 0.98, 0.03);

static float PidDownMotor0[3] = {1.3, 5.0, 0};
static float PidUpMotor0[3] = {3.0, 5.0, 0};
static float coeffSpeedDownMotor0 = 1;
static float coeffSpeedUpMotor0 = 1;

static float PidDownMotor1[3] = {0.75, 10.0, 0};
static float PidUpMotor1[3] = {10.0, 3.0, 0};
static float coeffSpeedDownMotor1 = 1;
static float coeffSpeedUpMotor1 = 1;

static float PidDownMotor2[3] = {5.0, 7.0, 0};
static float PidUpMotor2[3] = {13.0, 7.0, 0};
static float coeffSpeedDownMotor2 = 1;
static float coeffSpeedUpMotor2 = 1;

static float PidDownMotor3[3] = {7.0, 7.0, 0};
static float PidUpMotor3[3] = {13.3, 7.0, 0};
static float coeffSpeedDownMotor3 = 1;
static float coeffSpeedUpMotor3 = 1;

static float PidDownMotor4[3] = {0.75, 10.0, 0};
static float PidUpMotor4[3] = {10.5, 3.0, 0};
static float coeffSpeedDownMotor4 = 1;
static float coeffSpeedUpMotor4 = 1;

static float PidDownMotor5[3] = {1.3, 5.0, 0};
static float PidUpMotor5[3] = {3.0, 5.0, 0};
static float coeffSpeedDownMotor5 = 1;
static float coeffSpeedUpMotor5 = 1;

static float PidDownMotor6[3] = {10.0, 10.0, 0};
static float PidUpMotor6[3] = {10.0, 10.0, 0};
static float coeffSpeedDownMotor6 = 1;
static float coeffSpeedUpMotor6 = 1;

void motor0_body()
{
	while(1)
	{
		if(motor0.position == -1)
		{
			motor0.Stop();
		}
		else
		{
			if(motor0.position < 0)
			{
				motor0.position = 0;
			}
			if(motor0.position > 100)
			{
				motor0.position = 100;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot0.currentPosition - pot0.CalculatePot(motor0.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//down
				motor0.SetDirection(2);
				motor0.Pid.SetAllCoeff(coeffSpeedDownMotor0*PidDownMotor0[0], PidDownMotor0[1], PidDownMotor0[2]);
			}
			else
			{
				//up
				motor0.SetDirection(1);
				motor0.Pid.SetAllCoeff(coeffSpeedUpMotor0*PidUpMotor0[0], PidUpMotor0[1], PidUpMotor0[2]);
			}			
			
			motor0.Pid.SetSettedValue(pot0.CalculatePot(motor0.position));
			while( !pot0.IsValue(motor0.position, deltaPosSign) );
			motor0.Stop();
			
			motor0.position = -1;
		}
	}

}

void motor1_body()
{
	while(1)
	{
		if(motor1.position == -1)
		{
			motor1.Stop();
		}
		else
		{
			if(motor1.position < 0)
			{
				motor1.position = 0;
			}
			if(motor1.position > 100)
			{
				motor1.position = 100;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot1.currentPosition - pot1.CalculatePot(motor1.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//down
				motor1.SetDirection(2);
				motor1.Pid.SetAllCoeff(coeffSpeedDownMotor1*PidDownMotor1[0], PidDownMotor1[1], PidDownMotor1[2]);
			}
			else
			{
				//up
				motor1.SetDirection(1);
				motor1.Pid.SetAllCoeff(coeffSpeedUpMotor1*PidUpMotor1[0], PidUpMotor1[1], PidUpMotor1[2]);
			}			
			
			motor1.Pid.SetSettedValue(pot1.CalculatePot(motor1.position));
			while( !pot1.IsValue(motor1.position, deltaPosSign) );
			motor1.Stop();
			
			motor1.position = -1;
		}
	}
	
	
}

void motor2_body()
{
	
	while(1)
	{
		if(motor2.position == -1)
		{
			motor2.Stop();
		}
		else
		{
			if(motor2.position < 0)
			{
				motor2.position = 0;
			}
			if(motor2.position > 100)
			{
				motor2.position = 100;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot2.currentPosition - pot2.CalculatePot(motor2.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//down
				motor2.SetDirection(2);
				motor2.Pid.SetAllCoeff(coeffSpeedDownMotor2*PidDownMotor2[0], PidDownMotor2[1], PidDownMotor2[2]);
			}
			else
			{
				//up
				motor2.SetDirection(1);
				motor2.Pid.SetAllCoeff(coeffSpeedUpMotor2*PidUpMotor2[0], PidUpMotor2[1], PidUpMotor2[2]);
			}			
			
			motor2.Pid.SetSettedValue(pot2.CalculatePot(motor2.position));
			while( !pot2.IsValue(motor2.position, deltaPosSign) );
			motor2.Stop();
			
			motor2.position = -1;
		}
	}
	
	
}

void motor3_body()
{
	while(1)
	{
		if(motor3.position == -1)
		{
			motor3.Stop();
		}
		else
		{
			if(motor3.position < 0)
			{
				motor3.position = 0;
			}
			if(motor3.position > 100)
			{
				motor3.position = 100;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot3.currentPosition - pot3.CalculatePot(motor3.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//up
				motor3.SetDirection(2);
				motor3.Pid.SetAllCoeff(coeffSpeedUpMotor3*PidUpMotor3[0], PidUpMotor3[1], PidUpMotor3[2]);
			}
			else
			{
				//down
				motor3.SetDirection(1);				
				motor3.Pid.SetAllCoeff(coeffSpeedDownMotor3*PidDownMotor3[0], PidDownMotor3[1], PidDownMotor3[2]);
			}			
			
			motor3.Pid.SetSettedValue(pot3.CalculatePot(motor3.position));
			while( !pot3.IsValue(motor3.position, deltaPosSign) );
			motor3.Stop();
			
			motor3.position = -1;
		}
	}
	
	
}

void motor4_body()
{
	while(1)
	{
		if(motor4.position == motor4.positionStop)
		{
			motor4.Stop();
		}
		else
		{
			if(motor4.position < motor4.positionMin)
			{
				motor4.position = motor4.positionMin;
			}
			if(motor4.position > motor4.positionMax)
			{
				motor4.position = motor4.positionMax;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot4.currentPosition - pot4.CalculatePot(motor4.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//down
				motor4.SetDirection(2);
				motor4.Pid.SetAllCoeff(coeffSpeedDownMotor4*PidDownMotor4[0], PidDownMotor4[1], PidDownMotor4[2]);
			}
			else
			{
				//up
				motor4.SetDirection(1);
				motor4.Pid.SetAllCoeff(coeffSpeedUpMotor4*PidUpMotor4[0], PidUpMotor4[1], PidUpMotor4[2]);
			}			
			
			motor4.Pid.SetSettedValue(pot4.CalculatePot(motor4.position));
			while( !pot4.IsValue(motor4.position, deltaPosSign) );
			motor4.Stop();
			
			motor4.position = motor4.positionStop;
		}
	}
	
	
}

void motor5_body()
{
	
	while(1)
	{
		if(motor5.position == motor5.positionStop)
		{
			motor5.Stop();
		}
		else
		{
			if(motor5.position < motor5.positionMin)
			{
				motor5.position = motor5.positionMin;
			}
			if(motor5.position > motor5.positionMax)
			{
				motor5.position = motor5.positionMax;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot5.currentPosition - pot5.CalculatePot(motor5.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			if(deltaPos > 0)
			{
				//down
				motor5.SetDirection(2);
				motor5.Pid.SetAllCoeff(coeffSpeedDownMotor5*PidDownMotor5[0], PidDownMotor5[1], PidDownMotor5[2]);
			}
			else
			{
				//up
				motor5.SetDirection(1);
				motor5.Pid.SetAllCoeff(coeffSpeedUpMotor5*PidUpMotor5[0], PidUpMotor5[1], PidUpMotor5[2]);
			}			
			
			motor5.Pid.SetSettedValue(pot5.CalculatePot(motor5.position));
			while( !pot5.IsValue(motor5.position, deltaPosSign) );
			motor5.Stop();
			
			motor5.position = motor5.positionStop;
		}
	}
}

void motor6_body()
{
	while(1)
	{
		if(motor6.position == motor6.positionStop)
		{
			motor6.Stop();
		}
		else
		{
			if(motor6.position < motor6.positionMin)
			{
				motor6.position = motor6.positionMin;
			}
			if(motor6.position > motor6.positionMax)
			{
				motor6.position = motor6.positionMax;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = pot6.currentPosition - pot6.CalculatePot(motor6.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			motor6.Pid.SetAllCoeff(coeffSpeedDownMotor6*PidDownMotor6[0], PidDownMotor6[1], PidDownMotor6[2]);
			
			if(deltaPos > 0)
			{
				//right
				motor6.SetDirection(2);
			}
			else
			{
				//left
				motor6.SetDirection(1);
			}			
			
			motor6.Pid.SetSettedValue(pot6.CalculatePot(motor6.position));
			while( !pot6.IsValue(motor6.position, deltaPosSign) );
			motor6.Stop();
			
			motor6.position = motor6.positionStop;
		}
	}
}

void motor7_body()
{
	
	
}

void Trajectory(int8_t pos0, int8_t pos1, int8_t pos2, int8_t pos3, int8_t pos4, int8_t pos5, int8_t pos6)
{
	motor0.SetPosition(pos0);
	motor1.SetPosition(pos1);
	motor2.SetPosition(pos2);
	motor3.SetPosition(pos3);
	motor4.SetPosition(pos4);
	motor5.SetPosition(pos5);
	motor6.SetPosition(pos6);
	
	while( (motor0.position != -1) || (motor1.position != -1) || (motor2.position != -1) || (motor3.position != -1) ||
					(motor4.position != -1) || (motor5.position != -1) ||	(motor6.position != -1) );
	
	wait(0.2);
}

void GoToNull()
{
	motor0.Stop();
	motor1.Stop();
	motor2.Stop();
	motor3.Stop();
	motor4.Stop();
	motor5.Stop();
	motor6.Stop();
	motor7.Stop();

	motor3.flagInvertPosition=1;
	
	Trajectory(0, 0, 0, 0, 0, 0, 60);
		
	wait(1);
}



void Trajectory1()
{
	Trajectory(100, 50, 100, 100, 50, 100, -1);
	wait(1);
	GoToNull();
	
}

void Trajectory2()
{
	Trajectory(0, 0, 50, 50, 0, 0, -1);
	Trajectory(0, 0, 50, 100, 0, 0, 0);
	Trajectory(0, 0, 100, 50, 0, 0, 100);
	Trajectory(0, 0, 50, 100, 0, 0, 0);
	Trajectory(0, 0, 100, 50, 0, 0, 100);
	
	wait(1);
	GoToNull();
	
}

void Trajectory3()
{
	Trajectory(100, 0, 100, 100, 0, 100, 0);
	Trajectory(100, 0, 0, 0, 0, 100, 100);
	Trajectory(0, 0, 0, 0, 0, 0, 60);
	
	wait(1);
	GoToNull();
	
}

void Trajectory4()
{
	Trajectory(100, 0, 100, 100, 0, 100, 0);
	Trajectory(100, 100, 100, 100, 100, 100, 100);
	Trajectory(100, 0, 100, 100, 0, 100, 0);
	Trajectory(100, 0, 0, 0, 0, 100, 100);
	Trajectory(0, 0, 0, 0, 0, 0, 60);
	
	wait(1);
	GoToNull();
	
}

