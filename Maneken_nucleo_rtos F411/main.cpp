#include "mbed.h"

#include "my_pid.h"
#include "my_motor.h"
#include "my_potentiometer.h"
//#include "my_debugBuffer.h"

void UartRX(void);

int count=0;

Serial pc(SERIAL_TX, SERIAL_RX);

Thread t1, t2;

DigitalOut led1(LED1);

My_potentiometer pot1(PC_0, 0.28, 0.64, 0.02); //Pin, pot_min, pot_max, delta
My_potentiometer pot2(PC_3, 0.74, 0.98, 0.01);

// for motor
My_motor motor1(PB_13, PB_14, PA_10);	//A,B,PWM
My_motor motor2(D5, D6, D7);

// threads
uint8_t flag_thread1=0, flag_thread2=0;

// for debug
DigitalOut test1(PC_10);
//My_DebugBuffer debugBuffer(300, 300);
uint8_t flag_buf=0;

void motor1_body()
{
	float speedMotor=1;
	
	motor1.Pid.SetAllCoeff(3.0, 2.0, 0);
	
	while (1) 
	{ 
		//motor1.SetSpeed(speedMotor);       
		//motor1.Pid.settedValue = speedMotor;
		motor1.Pid.SetSettedValue(140);
		motor1.SetDirection(2);
		while( !pot1.IsMinValue() );
		motor1.Stop();
		//debugBuffer.PrintBuffer1_2(&pc);
		wait(0.5);
		
		//motor1.SetSpeed(speedMotor);
		//motor1.Pid.settedValue = speedMotor;
		motor1.Pid.SetSettedValue(140);
		motor1.SetDirection(1);
		while( !pot1.IsMaxValue() );
		motor1.Stop();
		wait(0.5);        
	}
}

void motor2_body()
{
	float speedMotor=0.05;
	
    while(1)
    {
        //motor2.SetSpeed(0.3);
				motor2.Pid.settedValue = speedMotor;
        motor2.SetDirection(2);
        while( !pot2.IsMinValue() );
        motor2.Stop();
        wait(0.5);
        
        //motor2.SetSpeed(0.3);
				motor2.Pid.settedValue = speedMotor;
        motor2.SetDirection(1);
        while( !pot2.IsMaxValue() );
        motor2.Stop();
        wait(0.5);        
    }
}

void time()
{
    static int i1=0;
    const int deltaT = 5; // ms        
    i1++;
    
    
    if(i1==deltaT)
    {
			test1=1;
			
      pot1.Refresh();
			pot2.Refresh();
			i1=0;
			
			if(motor1.flagRotate==1)
			{
				//debugBuffer.WriteValue(pot1.omega);
				//debugBuffer.WriteValue2(pot1.currentPosition);
			}
			
			motor1.PidStep(pot1.omega/deltaT);
			motor2.PidStep(pot2.omega/deltaT);
			
			test1=0;
    }

}

void UartRX()
{
    uint8_t b=pc.getc();
		float test_speed=0.2;
		float wait_time=0.1;
    
    if(b==1)
    {
        motor1.SetSpeed(test_speed);
        motor1.SetDirection(1);
        wait(wait_time);
        motor1.Stop();        
    }
    else if(b==2)
    {
        motor1.SetSpeed(test_speed);
        motor1.SetDirection(2);
        wait(wait_time);
        motor1.Stop();        
    }
    else if(b==3)
    {
        motor2.SetSpeed(test_speed);
        motor2.SetDirection(1);
        wait(wait_time);
        motor2.Stop();        
    }
    else if(b==4)
    {
        motor2.SetSpeed(test_speed);
        motor2.SetDirection(2);
        wait(wait_time);
        motor2.Stop();        
    }
    
    else if(b==5)
    {
         pc.printf("pot1_min=%f, pot1_max=%f, pot2_min=%f, pot2_max=%f\r\n", pot1.min, pot1.max, pot2.min, pot2.max);
    }
    
    else if(b==6)
    {
        pot1.min=pot1.GetPosition();
				pc.printf("pot1_min=%f\r\n", pot1.min);
    }
    else if(b==7)
    {
        pot1.max=pot1.GetPosition();
				pc.printf("pot1_max=%f\r\n", pot1.max);
    }
    else if(b==8)
    {
        pot2.min=pot2.GetPosition();
				pc.printf("pot2_min=%f\r\n", pot2.min);
    }
    else if(b==9)
    {
        pot2.max=pot2.GetPosition();
				pc.printf("pot2_max=%f\r\n", pot2.max);
    }
    
    else if(b==10)
    {
         flag_thread1=1;
    }
    else if(b==11)
    {
         flag_thread2=1;
    }
		else if(b==12)
    {
        pc.printf("pot1=%f\r\n", pot1.GetPosition());
    }
		else if(b==13)
    {
        pc.printf("pot2=%f\r\n", pot2.GetPosition());
    }
		else if(b==14)
    {
         flag_thread1=2;
    }
    else if(b==15)
    {
         flag_thread2=2;
    }
		else if(b==16)
    {
         pc.printf("IsMax1=%s\r\n",pot1.IsMaxValue()?"true":"false");
    }
		else if(b==17)
    {
         pc.printf("IsMax2=%s\r\n",pot2.IsMaxValue()?"true":"false");
    }
		else if(b==18)
    {
         //debugBuffer.PrintBuffer(&pc);
    }
		else if(b==19)
    {
         flag_buf=1;
    }
    
}



int main()
{
    pc.baud(256000);
    pc.attach(&UartRX);
    pc.printf("\n\n*** RTOS maneken start ***\n");

    motor1.Stop();
    motor2.Stop();
    
  
		//t1.start(motor1_body);
	Ticker tim;	
	tim.attach_us(&time, 5000);
	
    while (true) 
    {
				if(flag_thread1==1)
				{
					t1.start(motor1_body);
					flag_thread1=0;
				}
				else if(flag_thread1==2)
				{
					t1.terminate();
					flag_thread1=0;
					motor1.Stop();
				}
				
				if(flag_thread2==1)
				{
					t2.start(motor2_body);
					flag_thread2=0;
				}
				else if(flag_thread2==2)
				{
					t2.terminate();
					flag_thread2=0;
					motor2.Stop();
				}
				
				if(flag_buf==1)
				{
					//debugBuffer.DeleteBuf();
					flag_buf=0;
				}
				
        led1 = !led1;
        wait(0.5);
    }
}
