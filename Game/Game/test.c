#define _CRT_SECURE_NO_WARNINGS 1 
#include<string.h>
#include<stdlib.h>
#include<windows.h>


#include"game.h"

void menu()
{
	printf("**************************************\n");
	printf("*****  1.Playgame      0.Exit   ******\n");
	printf("**************************************\n");
}
void game()
{
	char ret = 0;
	//创建数组 存在玩家走出的棋盘信息
	char board[ROW][COL] = {0};//全部是空格
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	//下棋
	while(1)
	{
		//先玩家下棋
	
		PlayerMove(board,ROW,COL);
		system("Cls");
		DisplayBoard(board,ROW,COL);
		//判断玩家是否赢

//		ret = IsWin(board,ROW,COL);
		ret = IsWin_bigboard(board,ROW,COL);
		if(ret !='C')
		{
			break;
		}
		//电脑下棋
		ComputerMove(board,ROW,COL);
		Sleep(1000);
		system("Cls");
		DisplayBoard(board,ROW,COL);
		//判断电脑是否赢
//		ret = IsWin(board,ROW,COL);
		ret = IsWin_bigboard(board,ROW,COL);
		if(ret !='C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("玩家赢\n");
	}
	else if(ret == '#')
	{
		printf("电脑赢\n");
	}
	else 
	{
		printf("平局\n");
	}
	
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
	
		switch(input)
		   {
	         case 1: game();
					 break;
			 case 0: printf("退出游戏\n");
					 break;
			 default:printf("请重新选择\n");
				 break;
			}
	}while(input != 0);
}

int main()
{
	test();

	return 0;
}