#define _CRT_SECURE_NO_WARNINGS 1 
#include<string.h>
#include<stdio.h>

#include"game.h"


void InitBoard(char board[ROW][COL],int row,int col)
{
   int i = 0;
   int j = 0;
   for(i=0;i<row;i++)
   {
		for(j=0;j<col;j++)
		{
			board[i][j] = ' ';		
		} 
   }
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)//��ӡһ������
	{
		
		for(j=0;j<col;j++)//��ӡһ������
			{
				printf(" %c ",board[i][j]);
				if(j<col-1)
					{
						printf("|");
					}				
			}
		printf("\n");

		if(i<row-1)//��ӡ�ָ���
		{
			for(j=0;j<col;j++)
				{
					printf("---");	
					if(j<col-1)
						{
							printf("|");
						}									
				}
			printf("\n");
		}		
	}
}

void PlayerMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("�����:>\n");
	
	while(1)
	{
		printf("������Ҫ�µ�����:>\n");
		scanf("%d%d",&x,&y);

		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("�����걻ռ��");
			}
		}
		else
		{
			printf("����Ƿ����������룡\n");
		}
	}
}

void ComputerMove(char board[ROW][COL],int row,int col)
{	
	int x = 0;
	int y = 0;
	printf("������:>\n");

	while(1)
	{
		x = rand()%row;
		y = rand()%col;
		if(board[x][y] == ' ')
		{
			board[x][y] = '#';	
			break;
		}
	}
}

int IsFull(char board[ROW][COL],int row,int col)
{
	int i = 0;
	for(i=0;i<row;i++)
	{
		int j = 0;
		for(j=0;j<col;j++)
		{
			if(board[i][j] == ' ')
				return 0;//û��
		}
	}
	return 1;//����
}

//char IsWin(char board[ROW][COL],int row,int col)
//{
//	int i = 0;
//	for(i=0;i<row;i++)
//	{
//		if(board[i][0] == board[i][1]&&board[i][1] == board[i][2]&&board[i][1]!=' ')//�ж�ˮƽ״̬
//		{
//			return board[i][1];
//		}
//	}
//	
//	for(i=0;i<col;i++)
//	{
//		if(board[0][i] == board[1][i]&&board[1][i] == board[2][i]&&board[1][i]!=' ')//�жϴ�ֱ״̬
//		{
//			return board[1][i];
//		}
//	}
//	
//	if(board[0][0] == board[1][1]&&board[1][1] == board[2][2]&&board[1][1]!=' ')//�ж�135��б��״̬
//			return board[1][1];
//
//	if(board[2][0] == board[1][1]&&board[1][1] == board[0][2]&&board[1][1]!=' ')//�ж�45��б��״̬
//			return board[1][1];
//	//�ж��Ƿ�ƽ��
//	if(1 == IsFull(board,ROW,COL))
//	{
//		return 'Q';
//	}
//
//    return 'C';
//}

char IsWin_bigboard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
				if(board[i][j] == board[i][j+1]&&board[i][j+1] == board[i][j+2]&&board[i][j+2] == board[i][j+3]&&board[i][j+3] == board[i][j+4]&&board[i][j]!=' ')//�ж�ˮƽ״̬
			{
				return board[i][j];
			}
		}
	}
	
	for(i=0;i<col;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j] == board[i+1][j]&&board[i+1][j] == board[i+2][j]&&board[i+2][j] == board[i+3][j]&&board[i+3][j] == board[i+4][j]&&board[i][j]!=' ')//�жϴ�ֱ״̬
			{
				return board[i][j];
			}
		}
	}
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j] == board[i+1][j+1]&&board[i+1][j+1] == board[i+2][j+2]&&board[i+2][j+2] == board[i+3][j+3]&&board[i+3][j+3] == board[i+4][j+4]&&board[i][j]!=' ')
			return board[i][j];

			if(board[i][j] == board[i-1][j+1]&&board[i-1][j+1] == board[i-2][j+2]&&board[i-2][j+2] == board[i-3][j+3]&&board[i-3][j+3] == board[i-4][j+4]&&board[i][j]!=' ')
			return board[i][j];
		}
	}

	//�ж��Ƿ�ƽ��
	if(1 == IsFull(board,ROW,COL))
	{
		return 'Q';
	}

    return 'C';
}