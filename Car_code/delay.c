#include "delay.h"


/*------------------延时程序-------------------
入口参数：dly
出口参数：无

dly=10  延时4.97us   dly=100  延时45.66us   dly=1000 延时452us
即dly=1对应0.45us
-----------------------------------------------*/
void delay(unsigned int dly)
{
	unsigned int i;
	
	for ( ; dly>0; dly--)
		for (i=0; i<50; i++);

}
