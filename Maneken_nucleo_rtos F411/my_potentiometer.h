#include "mbed.h"

class My_potentiometer
{
 
    protected:
 
    public:
        
				AnalogIn adc;
        float currentPosition;
				float oldPosition;
				float omega;
		
				float min;
				float max;
				float delta;
        
        My_potentiometer(PinName adc_pin, float _min, float _max, float _delta) : adc(adc_pin)
        {
            currentPosition=adc;
						oldPosition=currentPosition;
						Speed();
					
						min=_min;
						max=_max;
						delta=_delta;
        }
				
				void Speed()
				{
					omega=(currentPosition-oldPosition)*1000;
					if(omega<0)
					{
						omega=omega*(-1);
					}
					
					if(omega < 0.2f)
					{
						omega=0;
					}
				}
				
				float GetPosition()
				{
					return currentPosition;
				}
				
				void Refresh()
				{
					oldPosition=currentPosition;
					currentPosition=adc.read();
					
					Speed();
					
				}
				
				bool IsMinValue()
				{
					return !(currentPosition > (min + 0.5f*delta));
				}
				
				bool IsMaxValue()
				{
					return !(currentPosition < (max - 0.5f*delta));
				}
				
				bool IsValue(float value, int8_t sign)
				{
					float potValue = CalculatePot(value);
					
					bool a = (currentPosition < (potValue + 0.5f*delta) && currentPosition > (potValue - 0.5f*delta));
					bool b;
					
					if( (currentPosition - potValue)*sign > 0)
					{
						b=false;
					}
					else
					{
						b=true;
					}
					
					return a || b;
				}
				
				float CalculatePot(float value)
				{
					return (max-min)* (value/100) + min;
				}
};

