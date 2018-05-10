#include "motors_threads.h"

extern Serial pc;

// for motor
My_motor motor0(PB_13, PB_14, PA_10, PC_0, 0.49, 0.87, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor1(PB_15, PB_1, PB_3, PC_1, 0.71, 0.91, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor2(PB_2, PB_12, PB_5, PB_0, 0.55, 0.88, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor3(PA_11, PA_12, PB_4, PA_4, 0.00, 0.17, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor4(PC_5, PC_6, PB_10, PA_1, 0.54, 0.74, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor5(PB_6, PA_7, PA_8, PA_0, 0.35, 0.67, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor6(PA_6, PA_5, PA_9, PC_3, 0.70, 1.00, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta
My_motor motor7(PB_9, PB_8, PC_7, PC_2, 0.24, 0.39, 0.03);	//A,B,PWM, PinPot, pot_min, pot_max, delta



static float PidDownMotor0[3] = {1.3, 35.0, 0};
static float PidUpMotor0[3] = {3.0, 35.0, 0};

static float PidDownMotor1[3] = {0.75, 25.0, 0};
static float PidUpMotor1[3] = {10.0, 50.0, 0};

static float PidDownMotor2[3] = {5.0, 50.0, 0};
static float PidUpMotor2[3] = {13.0, 50.0, 0};

static float PidDownMotor3[3] = {7.0, 50.0, 0};
static float PidUpMotor3[3] = {13.3, 50.0, 0};

static float PidDownMotor4[3] = {0.75, 25.0, 0};
static float PidUpMotor4[3] = {10.5, 50.0, 0};

static float PidDownMotor5[3] = {1.3, 35.0, 0};
static float PidUpMotor5[3] = {3.0, 35.0, 0};

static float PidDownMotor6[3] = {15.0, 10.0, 0};

static float PidDownMotor7[3] = {2.5, 35.0, 0};
static float PidUpMotor7[3] = {5.0, 35.0, 0};

static float coeffSpeedDownMotor = 2.5;
static float coeffSpeedUpMotor = 2.5;

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
			float deltaPos = motor0.pot.currentPosition - motor0.pot.CalculatePot(motor0.position);
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
				motor0.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor0[0], PidDownMotor0[1], PidDownMotor0[2]);
			}
			else
			{
				//up
				motor0.SetDirection(1);
				motor0.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor0[0], PidUpMotor0[1], PidUpMotor0[2]);
			}			
			
			motor0.Pid.SetSettedValue(motor0.pot.CalculatePot(motor0.position));
			
			if( motor0.pot.IsValue(motor0.position, deltaPosSign) )
			{
				motor0.Stop();
			
				motor0.position = -1;
			}
			
			//motor0.debugBuffer.PrintBuffer(&pc);
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
			float deltaPos = motor1.pot.currentPosition - motor1.pot.CalculatePot(motor1.position);
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
				motor1.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor1[0], PidDownMotor1[1], PidDownMotor1[2]);
			}
			else
			{
				//up
				motor1.SetDirection(1);
				motor1.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor1[0], PidUpMotor1[1], PidUpMotor1[2]);
			}			
			
			motor1.Pid.SetSettedValue(motor1.pot.CalculatePot(motor1.position));
			
			if( motor1.pot.IsValue(motor1.position, deltaPosSign) )
			{
				motor1.Stop();
			
				motor1.position = -1;
			}
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
			float deltaPos = motor2.pot.currentPosition - motor2.pot.CalculatePot(motor2.position);
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
				motor2.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor2[0], PidDownMotor2[1], PidDownMotor2[2]);
			}
			else
			{
				//up
				motor2.SetDirection(1);
				motor2.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor2[0], PidUpMotor2[1], PidUpMotor2[2]);
			}			
			
			motor2.Pid.SetSettedValue(motor2.pot.CalculatePot(motor2.position));
			
			if( motor2.pot.IsValue(motor2.position, deltaPosSign) )
			{
				motor2.Stop();
			
				motor2.position = -1;
			}
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
			float deltaPos = motor3.pot.currentPosition - motor3.pot.CalculatePot(motor3.position);
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
				motor3.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor3[0], PidUpMotor3[1], PidUpMotor3[2]);
			}
			else
			{
				//down
				motor3.SetDirection(1);				
				motor3.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor3[0], PidDownMotor3[1], PidDownMotor3[2]);
			}			
			
			motor3.Pid.SetSettedValue(motor3.pot.CalculatePot(motor3.position));
			if( motor3.pot.IsValue(motor3.position, deltaPosSign) )
			{
				motor3.Stop();
			
				motor3.position = -1;
			}
			
			//motor3.debugBuffer.PrintBuffer(&pc);
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
			float deltaPos = motor4.pot.currentPosition - motor4.pot.CalculatePot(motor4.position);
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
				motor4.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor4[0], PidDownMotor4[1], PidDownMotor4[2]);
			}
			else
			{
				//up
				motor4.SetDirection(1);
				motor4.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor4[0], PidUpMotor4[1], PidUpMotor4[2]);
			}			
			
			motor4.Pid.SetSettedValue(motor4.pot.CalculatePot(motor4.position));
			
			if( motor4.pot.IsValue(motor4.position, deltaPosSign) )
			{
				motor4.Stop();
			
				motor4.position = motor4.positionStop;
			}
			
			//motor4.debugBuffer.PrintBuffer(&pc);
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
			float deltaPos = motor5.pot.currentPosition - motor5.pot.CalculatePot(motor5.position);
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
				motor5.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor5[0], PidDownMotor5[1], PidDownMotor5[2]);
			}
			else
			{
				//up
				motor5.SetDirection(1);
				motor5.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor5[0], PidUpMotor5[1], PidUpMotor5[2]);
			}			
			
			motor5.Pid.SetSettedValue(motor5.pot.CalculatePot(motor5.position));
			
			if( motor5.pot.IsValue(motor5.position, deltaPosSign) )
			{
				motor5.Stop();
			
				motor5.position = motor5.positionStop;
			}
			
			//motor5.debugBuffer.PrintBuffer(&pc);
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
			float deltaPos = motor6.pot.currentPosition - motor6.pot.CalculatePot(motor6.position);
			float deltaPosSign;
			
			if(deltaPos>=0)
			{
				deltaPosSign = 1;
			}
			else
			{
				deltaPosSign = -1;
			}
			
			motor6.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor6[0], PidDownMotor6[1], PidDownMotor6[2]);
			
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
			
			motor6.Pid.SetSettedValue(motor6.pot.CalculatePot(motor6.position));
			
			if( motor6.pot.IsValue(motor6.position, deltaPosSign) )
			{
				motor6.Stop();
			
				motor6.position = motor6.positionStop;
			}
			
			//motor6.debugBuffer.PrintBuffer(&pc);
		}
	}
}

void motor7_body()
{
	while(1)
	{
		if(motor7.position == -1)
		{
			motor7.Stop();
		}
		else
		{
			if(motor7.position < 0)
			{
				motor7.position = 0;
			}
			if(motor7.position > 100)
			{
				motor7.position = 100;
			}
			// opredelit napravlenie i koefficienti pid
			float deltaPos = motor7.pot.currentPosition - motor7.pot.CalculatePot(motor7.position);
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
				motor7.SetDirection(2);
				motor7.Pid.SetAllCoeff(coeffSpeedDownMotor*PidDownMotor7[0], PidDownMotor7[1], PidDownMotor7[2]);
			}
			else
			{
				//up
				motor7.SetDirection(1);
				motor7.Pid.SetAllCoeff(coeffSpeedUpMotor*PidUpMotor7[0], PidUpMotor7[1], PidUpMotor7[2]);
			}			
			
			motor7.Pid.SetSettedValue(motor7.pot.CalculatePot(motor7.position));
			
			if( motor7.pot.IsValue(motor7.position, deltaPosSign) )
			{
				motor7.Stop();
			
				motor7.position = -1;
			}
			
			//motor0.debugBuffer.PrintBuffer(&pc);
		}
	}

}

void Trajectory(int8_t pos0, int8_t pos1, int8_t pos2, int8_t pos3, int8_t pos4, int8_t pos5, int8_t pos6)
{
	//motor0.SetPosition(pos0);
	motor1.SetPosition(pos1);
	motor2.SetPosition(pos2);
	motor3.SetPosition(pos3);
	motor4.SetPosition(pos4);
	motor5.SetPosition(pos5);
	motor6.SetPosition(pos6);
	motor7.SetPosition(pos0);
	
	while( (motor0.position != -1) || (motor1.position != -1) || (motor2.position != -1) || (motor3.position != -1) ||
					(motor4.position != -1) || (motor5.position != -1) ||	(motor6.position != -1) || (motor7.position != -1) );
	
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

