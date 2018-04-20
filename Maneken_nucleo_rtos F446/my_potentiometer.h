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
					
					if(omega<3)
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
					return !(currentPosition > (min+delta));
				}
				
				bool IsMaxValue()
				{
					return !(currentPosition < (max-delta));
				}
};

