#define _CRT_SECURE_NO_WARNINGS 1 
#include<math.h>

#include"game.h"

void menu()
{
	printf("******************************\n");
	printf("******   1.Playgame    *******\n");
	printf("******   0.Exit        *******\n");
	printf("******************************\n");


}
void game()
{
	//雷的信息存储
	//1.布置好雷的信息
	char mine[ROWS][COLS] = {0};//11*11
	//2.排查出的雷信息
	char show[ROWS][COLS] = {0};
	//初始化
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show,ROWS,COLS,'*');
	////打印棋盘
	//DispalyBoard(mine,ROW,COL);
	DispalyBoard(show,ROW,COL);
	////布置雷
	Setmine(mine,ROW,COL);
	DispalyBoard(mine,ROW,COL);
	////扫雷
	Findmine(mine,show,ROW,COL);

}
void test()
{
	int input = 0;
	do
	{
		srand((unsigned)time(NULL));
		menu();
		printf("请选择;>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:game();
				break;
			case 0:
				printf("退出游戏");
				break;
			default:
				printf("请重新选择！\n");	
				break;
		}
	
	}while(input);


}

int main()
{
	test();
	return 0;

}