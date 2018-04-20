#include "mbed.h"
#include <math.h>

class My_pid
{
 
    protected:
 
    public:
            
        float kp, kd, ki;                               // coefficients of PID
        float integral, err, old_err;       // integral component, errors
        float settedValue, real_value; // 
        float out;                                          // output of PID
        float min_out, max_out;                 // minimum and maximum values of output
               
        //constructor of the class
//      My_pid(float kp_set, float kd_set, float ki_set)
//      {
//          kp=kp_set;
//          kd=kd_set;
//          ki=ki_set;
//          
//          integral=0;
//          err=0;
//          old_err=0;
//          
//          setted_value=0;
//          real_value=0;
//          
//          set_min_max(-50,50);
//      }
        
        //constructor of the class
        My_pid()
        {
            
            kp=5;
            kd=1;
            ki=0.00;
            
            integral=0;
            err=0;
            old_err=0;
            
            settedValue=0;
            real_value=0;
            
            
            
            set_min_max(-50,50);
            
        }
        
        //Setting new parameters
        void set_min_max(float min, float max)
        {
            min_out=min;
            max_out=max;
        }
        void set_kp(float new_kp)
        {
            kp=new_kp;
        }
        void set_kd(float new_kd)
        {
            kd=new_kd;
        }
        void set_ki(float new_ki)
        {
            ki=new_ki;
        }
        void set_all_coeff(float new_kp, float new_kd, float new_ki)
        {
            kp=new_kp;
            kd=new_kd;
            ki=new_ki;
        }
        
        //calculate of control action
        float CalculatePid(float real_value1)
        {
            real_value=real_value1;
            err=settedValue-real_value;
            
            integral+=(err+old_err)/2;
            
            out=kp*err + kd*(err-old_err)+ ki*integral;
            
            if(out<min_out)
            {
                out=min_out;
            }
            if(out>max_out)
            {
                out=max_out;
            }
            
            old_err=err;
            
            return out;
        }
        
        
        
        void ResetOnZero()
        {
            integral=0;
            real_value=0;
            settedValue=0;
            out=0;
            err=0;
            old_err=0;      
            
        }
        

};
