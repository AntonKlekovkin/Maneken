#include "mbed.h"

class My_motor
{
 
    protected:
 
    public:
            
        DigitalOut direct1;
        DigitalOut direct2;
        PwmOut speed;
        My_pid Pid;
        char flag_start;
        char flagRotate;
        char flag_dir;
        float omega;
        int pulse_enc;
        char direction;
		
				char flagInvertPosition;
				float position;
				const float positionMin = 0;
				const float positionMax = 100;
				const float positionStop = -1;
        
        My_motor(PinName dir1, PinName dir2, PinName pwm) : direct1(dir1), direct2(dir2), speed(pwm)
        {
						wait(0.1);
//					
//						positionMin = 0;
//						positionMax = 100;
//						positionStop = -1;
						position = positionStop;
					
            flag_start=0;
            flagRotate=0;
            flag_dir=0;
            SetSpeed(0);
            direction=0;
						Stop();
					flagInvertPosition=0;
        }
        
				void SetPosition(float pos)
				{
					if(flagInvertPosition == 0)
					{
						position = pos;
					}
					else
					{
						position = positionMax - pos;
					}
				}
				
        void SetSpeed(float sp)
        {
            speed=1-sp;

						if( GetSpeed() != 0 && direction != 0)
						{
							flagRotate=1;
						}
						else
						{
							flagRotate=0;
						}
        }
        
        float GetSpeed()
        {
            return 1-speed;    
        }
				
				void PidStep(float newValue)
				{
					if(Pid.enabled == 1)
					{
						float newSpeed;
						newSpeed = Pid.CalculatePid(newValue)/100 + GetSpeed();
						
						SetSpeed(newSpeed);
					}
				}
        
        void SetDirection(int dir)
        {
            if(dir==1)
            {
                direction=1;
                direct1=1;
                direct2=0;
            }
            else if(dir==2)
            {
                direction=2;
                direct1=0;
                direct2=1;
            }
            else
            {
                direction=0;
                direct1=0;
                direct2=0;
            }
						
						if( GetSpeed() != 0 && direction != 0)
						{
							flagRotate=1;
						}
						else
						{
							flagRotate=0;
						}
        }
        
        void AnotherDirection()
        {
            if(direction==1)
            {
                SetDirection(2);
            }
            else if(direction==2)
            {
                SetDirection(1);
            }
        }
        void Stop()
        {
            SetDirection(0);
            SetSpeed(0);
            flagRotate=0;
						Pid.ResetOnZero();
        }

};
