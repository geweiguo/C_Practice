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
	//�������� ��������߳���������Ϣ
	char board[ROW][COL] = {0};//ȫ���ǿո�
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	//����
	while(1)
	{
		//���������
	
		PlayerMove(board,ROW,COL);
		system("Cls");
		DisplayBoard(board,ROW,COL);
		//�ж�����Ƿ�Ӯ

//		ret = IsWin(board,ROW,COL);
		ret = IsWin_bigboard(board,ROW,COL);
		if(ret !='C')
		{
			break;
		}
		//��������
		ComputerMove(board,ROW,COL);
		Sleep(1000);
		system("Cls");
		DisplayBoard(board,ROW,COL);
		//�жϵ����Ƿ�Ӯ
//		ret = IsWin(board,ROW,COL);
		ret = IsWin_bigboard(board,ROW,COL);
		if(ret !='C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if(ret == '#')
	{
		printf("����Ӯ\n");
	}
	else 
	{
		printf("ƽ��\n");
	}
	
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&input);
	
		switch(input)
		   {
	         case 1: game();
					 break;
			 case 0: printf("�˳���Ϸ\n");
					 break;
			 default:printf("������ѡ��\n");
				 break;
			}
	}while(input != 0);
}

int main()
{
	test();

	return 0;
}