1/*****************************************************************
 *   ���ܣ��綯����������										 *
 *	    1���������Σ�											 *
 *	       ����10���ڣ�P2.0�������1,10���ָ����ƣ�			 *
 *	    2��   �����                      �����				 *
 *	          P1.0                        P2.0					 *
 *		     �з� 0                       0 ����				 *
 *		     ��ʼ״̬�޷� 1			   1 ������				     *
 *		     �з� �� �޷� 0 -> 1		   0 ��ʱһСʱ��Ϊ 1	 *
 *															     *
 *		��д�ˣ�Greg Ge										     *
 *		�汾��  V00												 *
 *		�޶����ڣ�2022��11��1��									 *
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
		printf("������!\n");
	}while(systimerCnt<=10000);
	systimerFlag = 0;

	while(1)
	{
	   if(INPIN_P10 == 0)//�з�
	   {
	   		windtoNoFlag = 1;
	   		windFlag = 1;	 //���з綨ʱ������������־
			nowindFlag = 0;	 //���޷綨ʱ��־
			nowindCnt = 0;	 //���޷�ʱ�ļ���
			nowindsecCnt = 0;
			if(windCnt >= FLITER_TIMER)	//�˲�100ms
			{
				windFlag = 0;
				OUTPIN_P20 = 0;	
				windFlag = 0;
				printf("�з磬�������!\n");
			}
		}
		
		else if((INPIN_P10 == 1)&&(windtoNoFlag == 0))//��ʼʱ�����޷�
	   {
	   		windFlag = 0;	 //�ر��з綨ʱ������������־			
			windCnt = 0;	 
			nowindFlag = 1;	 //���޷綨ʱ��־
			if(nowindCnt >= FLITER_TIMER)	//�˲�100ms
			{
				nowindFlag = 0;				
				nowindCnt = 0;
				OUTPIN_P20 = 1;	
			printf("��ʼʱ�����޷磬���������!\n");
			}	   
	   }
	   	else if((INPIN_P10 == 1)&&(windtoNoFlag == 1))//�з絽�޷�
	   {
	   		windFlag = 0;	 //�ر��з綨ʱ������������־			
			windCnt = 0;	 
			nowindFlag = 1;	 //���޷綨ʱ��־
		
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
				  
					printf("�з絽�޷磬�����ʱ�ر�!\n");
				}

			}	   
	   }

	}
}
