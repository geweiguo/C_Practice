#include "timer.h";
#include <intrins.h>

unsigned  char systimerFlag = 1;
unsigned int systimerCnt = 0;

unsigned  char windFlag = 0;
unsigned int windCnt = 0;

unsigned  char nowindFlag = 0;
unsigned int nowindCnt = 0;

unsigned  char windtoNoFlag = 0;
unsigned  int nowindsecCnt = 0;

void Timer0Init(void)		//1毫秒@12.000MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	ET0 = 1;
	EA  = 1;
	TR0 = 1;		
}

void timer0_ISR()interrupt 1
{
	TR0 = 0;
	TL0 = 0x18;
	TH0 = 0xFC;
	 if(systimerFlag == 1)
	 {
	   systimerCnt++;
	 }
	if(windFlag == 1)
	 {
	   windCnt++;
	 }
	if(nowindFlag == 1)
	 {
	   nowindCnt++;
	 }
	TR0 = 1;
	
}
