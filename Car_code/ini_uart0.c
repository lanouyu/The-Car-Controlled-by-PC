#include<lpc213x.h>
#include "global_variable_declare.h"

__irq void IRQ_uart0(void);

void ini_uart0()
{
    int Fdiv;
	int Fpclk;
	int UART_BPS;
	Fpclk=11059200;
	UART_BPS=9600;
    U0LCR=0x83;
    Fdiv=(Fpclk/16)/UART_BPS;
    U0DLM=Fdiv/256;
    U0DLL=Fdiv%256;
    U0LCR=0x03;

	PINSEL0=(PINSEL0&(~0x0f))|0x05;   //设置P0.0,P0.1为UART0
	U0FCR=0x01;	   //使能FIFO，触发点为1字符
	U0IER=0x01;    //允许接收中断
	VICIntSelect=0x00000000;    //设置所有中断分配为IRQ
    VICVectCntl0=0x20|0x06;   //外部中断0向量号
	VICVectAddr0=(int)IRQ_uart0;  //中断入口地址,与VICVectCntl0对应
	VICIntEnable=(1<<6);//中断使能
}

 __irq void IRQ_uart0(void)
 {
    rev_data=U0RBR;
	//while((U0LSR&0x40)==0);
    VICVectAddr=0x00;     //更新中断优先级
 }
