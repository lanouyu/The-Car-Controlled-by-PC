#include <lpc213x.h>
#include "servo.h"
/*-------------------------------------------------------
Motor_PortNo:舵机端口
Motor_Angle：舵机角度/速度（0--0.5ms，90--1.5ms，180--2.5ms）
--------------------------------------------------------*/
void Servo(unsigned int Motor_PortNo,unsigned int Motor_Angle)
{
	switch(Motor_PortNo)
	{
	    case 1:
		 	PINSEL1=(PINSEL1&(~(0x03<<10)))|(0x01<<10);break;      //选择PWM5  P0.21 舵机1
		case 2:
			PINSEL0=(PINSEL0&(~(0x03<<14)))|(0x02<<14);break;      //选择PWM2  P0.7 舵机2
		case 3:
		    PINSEL0=(PINSEL0&(~(0x03<<16)))|(0x02<<16);break;      //选择PWM4   P0.8 舵机3
		case 4:
		    PINSEL0=(PINSEL0&(~(0x03<<18)))|(0x02<<18);break;      //选择PWM6   P0.9 舵机4
		case 5:
		    PINSEL0=(PINSEL0&(~(0x03<<0)))|(0x02<<0); break;       //选择PWM1   P0.0 舵机5
		case 6:
		    PINSEL0=(PINSEL0&(~(0x03<<2)))|(0x02<<2);break;        //选择PWM3   P0.1 舵机6
		default: break;
	}
    PWMPR=0x0;                                       //时钟不分频
    PWMMCR=0x02;          //设置PWMMR0匹配时复位PWMTCR
    PWMPCR=0x7e00;          //允许PWM1-6输出，单边
    PWMMR0=11059200/1000*20;        //设置匹配速率  20ms
	 switch(Motor_PortNo) 
   	   {
//舵机0--0.5ms   90--1.5ms   180--2.5ms
//每转1°的脉宽=（2.5-0.5）/180=1/90ms
   	    	case 1:
   	    	PWMMR5   =11059200/(1000000/(100*Motor_Angle/9+500));break;	   
   	   	    case 2:
   	    	PWMMR2   =11059200/(1000000/(100*Motor_Angle/9+500));break;         
   	    	case 3:
   	    	PWMMR4   =11059200/(1000000/(100*Motor_Angle/9+500));break;          
   	   	    case 4:
   	    	PWMMR6   =11059200/(1000000/(100*Motor_Angle/9+500));break;           
			case 5:
			PWMMR1   =11059200/(1000000/(100*Motor_Angle/9+500));break;           
			case 6:
			PWMMR3   =11059200/(1000000/(100*Motor_Angle/9+500));break;  //占空比
			default: break;
		}
    PWMLER=0x7f;          //PWM0和PWM1-6匹配时锁存
    PWMTCR=0x02;          //复位PWMTCR
    PWMTCR=0x09;          //启动PWM输出


}
