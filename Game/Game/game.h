#define _CRT_SECURE_NO_WARNINGS 1 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define  ROW  10
#define  COL  10
//函数声明
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL],int row,int col);
char IsWin_bigboard(char board[ROW][COL],int row,int col);


//能告诉我们四种状态  
//玩家赢  ‘*’
//电脑赢  ‘#’
//平局		‘Q’
//继续游戏  ‘C’