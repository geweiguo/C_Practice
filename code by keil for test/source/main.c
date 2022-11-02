1/*****************************************************************
 *   功能：风动传感器控制										 *
 *	    1、开机屏蔽：											 *
 *	       开机10秒内，P2.0输出保持1,10秒后恢复控制；			 *
 *	    2、   输入口                      输出口				 *
 *	          P1.0                        P2.0					 *
 *		     有风 0                       0 工作				 *
 *		     初始状态无风 1			   1 不工作				     *
 *		     有风 变 无风 0 -> 1		   0 延时一小时变为 1	 *
 *															     *
 *		编写人：Greg Ge										     *
 *		版本：  V00												 *
 *		修订日期：2022年11月1日									 *
 *****************************************************************/
#include <reg51.h>
#include "timer.h";
#include <stdio.h>

sbit OUTPIN_P20 = P2^0;
sbit INPIN_P10 = P1^0;

#define FLITER_TIMER 	100
#define sec_TIMER 		100
#define Hour_TIMER	 	100

void main()
{
    Timer0Init();
	INPIN_P10 = 1;

	do
	{
		OUTPIN_P20 = 1;	 
		printf("开机中!\n");
	}while(systimerCnt<=10000);
	systimerFlag = 0;

	while(1)
	{
	   if(INPIN_P10 == 0)//有风
	   {
	   		windtoNoFlag = 1;
	   		windFlag = 1;	 //打开有风定时器技术工作标志
			nowindFlag = 0;	 //清无风定时标志
			nowindCnt = 0;	 //清无风时的技术
			nowindsecCnt = 0;
			if(windCnt >= FLITER_TIMER)	//滤波100ms
			{
				windFlag = 0;
				OUTPIN_P20 = 0;	
				windFlag = 0;
				printf("有风，电机工作!\n");
			}
		}
		
		else if((INPIN_P10 == 1)&&(windtoNoFlag == 0))//初始时就是无风
	   {
	   		windFlag = 0;	 //关闭有风定时器技术工作标志			
			windCnt = 0;	 
			nowindFlag = 1;	 //打开无风定时标志
			if(nowindCnt >= FLITER_TIMER)	//滤波100ms
			{
				nowindFlag = 0;				
				nowindCnt = 0;
				OUTPIN_P20 = 1;	
			printf("初始时就是无风，电机不工作!\n");
			}	   
	   }
	   	else if((INPIN_P10 == 1)&&(windtoNoFlag == 1))//有风到无风
	   {
	   		windFlag = 0;	 //关闭有风定时器技术工作标志			
			windCnt = 0;	 
			nowindFlag = 1;	 //打开无风定时标志
		
			if(nowindCnt >= sec_TIMER )	//1s
			{
				nowindCnt = 0;
				nowindsecCnt++;
				if(nowindsecCnt >= Hour_TIMER)
				{	
					OUTPIN_P20 = 1;	
					nowindsecCnt = 0;
					nowindFlag = 0;
					windtoNoFlag = 0;
				  
					printf("有风到无风，电机延时关闭!\n");
				}

			}	   
	   }

	}
}
