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
	//�׵���Ϣ�洢
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = {0};//11*11
	//2.�Ų��������Ϣ
	char show[ROWS][COLS] = {0};
	//��ʼ��
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show,ROWS,COLS,'*');
	////��ӡ����
	//DispalyBoard(mine,ROW,COL);
	DispalyBoard(show,ROW,COL);
	////������
	Setmine(mine,ROW,COL);
	DispalyBoard(mine,ROW,COL);
	////ɨ��
	Findmine(mine,show,ROW,COL);

}
void test()
{
	int input = 0;
	do
	{
		srand((unsigned)time(NULL));
		menu();
		printf("��ѡ��;>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:game();
				break;
			case 0:
				printf("�˳���Ϸ");
				break;
			default:
				printf("������ѡ��\n");	
				break;
		}
	
	}while(input);


}

int main()
{
	test();
	return 0;

}