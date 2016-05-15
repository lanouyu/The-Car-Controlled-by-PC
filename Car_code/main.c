#include <lpc213x.h>
#include "delay.h"
#include "servo.h"	
#include "ini_uart0.h"
#include "global_variable_define.h"
#include "global_variable_declare.h"

int main(void)
{
    ini_uart0();
	rev_data=0x0;
	while(1)
	{
	    rev_data=rev_data&0xf;
	    switch(rev_data)
		{
		    case 1:			              //直行
				Servo(2,45);
    	        Servo(2,45);
				Servo(3,135);
				Servo(3,135);
				delay(500);
			    break;
			case 2:			             //左转
			    Servo(2,135);
    	        Servo(2,135);
				Servo(3,135);
				Servo(3,135);
				delay(500);	
			    break;
			case 3:			             //右转
			    Servo(2,45);
				Servo(2,45);
				Servo(3,45);
				Servo(3,45);
				delay(500);	
			    break;
			case 4:					    //倒退
				Servo(2,135);
    	        Servo(2,135);
				Servo(3,45);
				Servo(3,45);
				delay(500);
				break;
			case 5:					    //停止
				PWMTCR=0x0;          //禁止PWM
			    break;
			default: break;
		}
	}
}
