#ifndef __TIMER_H__
#define __TIMER_H__
#include <intrins.h>

#include <reg51.h>
sfr AUXR =0x8E;

extern unsigned  char systimerFlag;
extern unsigned int systimerCnt;

extern unsigned  char windFlag ;
extern unsigned int windCnt;

extern unsigned  char nowindFlag;
extern unsigned int nowindCnt;

extern unsigned  char windtoNoFlag;
extern unsigned  int nowindsecCnt;

extern void Timer0Init()

#endif