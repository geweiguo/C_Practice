#define _CRT_SECURE_NO_WARNINGS 1 


#include"game.h"

void Initboard(char arr[ROWS][COLS],int row,int col,char x)
{
	int i = 0;
	int j = 0;

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j] = x;
		}
	}
}


void DispalyBoard(char arr[ROWS][COLS],int row,int col)
{

	int i = 0;
	int j = 0;

	for(i=0;i<=row;i++)
	{
		printf("%d ",i);//打印列号
	}
	printf("\n");

	for(i=1;i<=row;i++)
	{
		printf("%d ",i);//打印行号
		for(j=1;j<col+1;j++)
		{
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
}

void showmine(char show[ROWS][COLS],int row,int col)
{
	int i = 0;
	int j = 0;

	for(i=1;i<=row;i++)
	{	
		for(j=1;j<col+1;j++)
		{
			if (show[i][j] == '1')
				{
					show[i][j] = '@';
				}
		}	
	}
	DispalyBoard(show,row,col);


}

void Setmine(char arr[ROWS][COLS],int row,int col)
{
	int count = MineCount;
	int x = 0;
	int y = 0;

	while(count)
	{
		x = rand()%row+1;
		y = rand()%col+1;
		
		if(arr[x][y] == '0')
			{
				arr[x][y] = '1';
				count--;
			}
	}
}

int get_minecount(char mine[ROWS][COLS],int x,int y)
{
	return	mine[x-1][y-1]+
			mine[x-1][y]+
			mine[x-1][y+1]+
			mine[x][y-1]+
			mine[x][y+1]+
			mine[x+1][y-1]+
			mine[x+1][y]+
			mine[x+1][y+1]-8*'0';

}

int OpenSurrounding1(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)
{
		   /*int i = 0;
			
		   if(x>=1 && x<=row && y>=1 && y<= col)
		   {
				show[x][y] = '0';			
				for(i = x-1;i<=x;i++)
				{
					int j = 0;
					for(j = y-1;j<=y;j++)
					{
						if(show[i][j] == '*')
						{
							OpenSurrounding(mine,show,row,col,x,y);
						}
					}
				}

		   }*/


			
			show[x-1][y-1] = get_minecount(mine,x-1,y-1)+'0';
				if(get_minecount(mine,x-1,y-1) == 0 && x-1>=1 && x-1<=row && y-1>=1 && y-1 <= col)
				{
					OpenSurrounding1(mine,show,row,col,x-1,y-1);
				}

			show[x-1][y]   = get_minecount(mine,x-1,y)+'0';
				if(get_minecount(mine,x-1,y) == 0 && x-1>=1 && x-1<=row && y>=1 && y <= col)
				{
					OpenSurrounding1(mine,show,row,col,x-1,y);
				}

			show[x-1][y+1] = get_minecount(mine,x-1,y+1)+'0';
				if(get_minecount(mine,x-1,y+1) == 0 && x-1>=1 && x-1<=row && y+1>=1 && y+1 <= col)
				{
					OpenSurrounding1(mine,show,row,col,x-1,y+1);
				}

			show[x][y-1]   = get_minecount(mine,x,y-1)+'0';
				if(get_minecount(mine,x,y-1) == 0 && x>=1 && x<=row && y-1>=1 && y-1 <= col)
				{
					OpenSurrounding1(mine,show,row,col,x,y-1);
				}

			//show[x][y+1]   = get_minecount(mine,x,y+1)+'0';
			//	if(get_minecount(mine,x,y+1) == 0 && x>=1 && x<=row && y+1>=1 && y+1 <= col)
			//	{
			//		OpenSurrounding(mine,show,row,col,x,y+1);
			//	}

			//show[x+1][y-1] = get_minecount(mine,x+1,y-1)+'0';
			//	if(get_minecount(mine,x+1,y-1) == 0 && x+1>=1 && x+1<=row && y-1>=1 && y-1 <= col)
			//	{
			//		OpenSurrounding(mine,show,row,col,x+1,y-1);
			//	}

			//show[x+1][y]   = get_minecount(mine,x+1,y)+'0';
			//	if(get_minecount(mine,x+1,y) == 0 && x+1>=1 && x+1<=row && y>=1 && y <= col)
			//	{
			//		OpenSurrounding(mine,show,row,col,x+1,y);
			//	}

			//show[x+1][y+1] = get_minecount(mine,x+1,y+1)+'0';
			//	if(get_minecount(mine,x+1,y+1) == 0 && x+1>=1 && x+1<=row && y+1>=1 && y+1 <= col)
			//	{
			//		OpenSurrounding(mine,show,row,col,x+1,y+1);
			//	}

			
}
int OpenSurrounding2(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col,int x,int y)
{
			int count = 0;
			show[x][y+1]   = get_minecount(mine,x,y+1)+'0';
			count++;
				if(get_minecount(mine,x,y+1) == 0 && x>=1 && x<=row && y+1>=1 && y+1 <= col)
				{
					OpenSurrounding2(mine,show,row,col,x,y+1);
					count++;
				}

			show[x+1][y-1] = get_minecount(mine,x+1,y-1)+'0';
			count++;
				if(get_minecount(mine,x+1,y-1) == 0 && x+1>=1 && x+1<=row && y-1>=1 && y-1 <= col)
				{
					OpenSurrounding2(mine,show,row,col,x+1,y-1);
					count++;
				}

			show[x+1][y]   = get_minecount(mine,x+1,y)+'0';
			count++;
				if(get_minecount(mine,x+1,y) == 0 && x+1>=1 && x+1<=row && y>=1 && y <= col)
				{
					OpenSurrounding2(mine,show,row,col,x+1,y);
					count++;
				}

			show[x+1][y+1] = get_minecount(mine,x+1,y+1)+'0';
			count++;
				if(get_minecount(mine,x+1,y+1) == 0 && x+1>=1 && x+1<=row && y+1>=1 && y+1 <= col)
				{
					OpenSurrounding2(mine,show,row,col,x+1,y+1);
					count++;
				}
				return count;

}



void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int findcount = 0;
	while(1)
	{
	
		int i = 0;
		int j = 0;

		printf("请输入排查雷的坐标:>\n");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(mine[x][y] == '1')//1.踩雷了
			{
				printf("很遗憾，你被炸死了！\n");
				showmine(mine,row,col);
			again:	
				break;
			}
			
			else//2.排雷中
			{
				int count = get_minecount(mine,x,y);
				show[x][y] = count+'0';
				
				if(count == 0)
				{
					OpenSurrounding1(mine,show,row,col,x,y);
					OpenSurrounding2(mine,show,row,col,x,y);
					system("Cls");
					DispalyBoard(show,row,col);	
				}
				if(count != 0)
				{
					system("Cls");
					DispalyBoard(show,row,col);
				}	

			}

		}
		else
			printf("输入坐标非法，请重新输入！");

			findcount = 0;
			for(i=1;i<=row;i++)
			 {
				for(j=1;j<=col;j++)
					{
						if(show[i][j] != '*')
							{
								findcount++;	
								
								if((row*col-findcount) == MineCount )
									{
										printf("恭喜，你赢了！\n");
										showmine(mine,row,col);
										goto again;
									}	

							}

						}		
				}
		}
}

