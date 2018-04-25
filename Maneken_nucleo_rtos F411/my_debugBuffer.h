#include "mbed.h"

class My_DebugBuffer
{
	protected:
 
  
  public:
	
	float* buf1;
	int countBuffer1;
	int length1;
	
	float* buf2;
	int countBuffer2;
	int length2;
	
	
	My_DebugBuffer(int _length)
	{
		length1 = _length;
		countBuffer1=0;
		
		buf1	= new float[length1];
		
		for(int i=0; i<length1; i++)
		{
			buf1[i]=0;			
		}
	}
	
	My_DebugBuffer(int _length1, int _length2)
	{
		length1 = _length1;
		countBuffer1=0;
		
		buf1	= new float[length1];
		
		for(int i=0; i<length1; i++)
		{
			buf1[i]=0;			
		}
		
		length2 = _length2;
		countBuffer2=0;
		
		buf2	= new float[length2];
		
		for(int i=0; i<length2; i++)
		{
			buf2[i]=0;			
		}
	}
	
	void WriteValue(float value)
	{
		buf1[countBuffer1]=value;
		
		countBuffer1++;
		if(countBuffer1==length1)
		{
			countBuffer1=0;
		}
	}
	
	void WriteValue2(float value)
	{
		buf2[countBuffer2]=value;
		
		countBuffer2++;
		if(countBuffer2==length2)
		{
			countBuffer2=0;
		}
	}
	
	
	
	void PrintBuffer(Serial* u)
	{
		int i;
			
		for(i=0;i<length1;i++)
		{
			u->printf("%d %f\r\n", i, buf1[i] );	
		}

	}
	
	void PrintBuffer1_2(Serial* u)
	{
		int i;
			
		for(i=0;i<length1;i++)
		{
			u->printf("%d %f %f\r\n", i, buf1[i], buf2[i] );	
		}

	}
	
	void DeleteBuf()
	{
		delete [] buf1;
		delete [] buf2;
	}
	
};
