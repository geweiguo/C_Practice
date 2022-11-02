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

void Timer0Init(void)		//1����@12.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x18;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
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
