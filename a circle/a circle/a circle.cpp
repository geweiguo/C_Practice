#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
//���������Һ������� ��������
//����һ�������λ����ߣ���һ��Ϊ��ɫ���ڶ���Ϊ��ɫ�뱳����ɫ��ɫһ�£��Ӷ��ﵽ������һ����ɫЧ����
//void main()
//{
//	initgraph(480,320);
//	setfillcolor(WHITE);
//	bar(0,0,480,320);
//	setcolor(BLACK); int x,y;
//	int x1;
//	float t,k;
//
//	while(1)
//	{
//	  //cleardevice();//�������Ϊ���˳���ԭ��������ԭ������Ļ��ɫ�����Ϊ��ɫ��
//		for(x1=0;x1>-480;x1--)
//			{
//				k=2*3.1415926/480*x1;
//				for(x=0;x<=480;x++)
//				{
//					t=2*3.1415926/480*x+k;
//					y=-(int)(100*sin(t))+160; 
//					putpixel(x,y,GREEN); //��һ��������ɫΪGREEN��
//						if(x==0)
//						{
//							setfillcolor(RED);
//							fillcircle(0,y,10);
//						}
//					setcolor(BLACK);
//					line(0,160,480,160);
//				} 
//
//				//getchar();//�������Ϊ���˳���ԭ��������ԭ����
//
//				for(x=0;x<=480;x++)
//				{
//					t=2*3.1415926/480*x+k;
//					y=-(int)(100*sin(t))+160;
//					putpixel(x,y,WHITE);//�ڶ����������������һ�����ߣ�ԭ����ɫΪWHITE���뱳����ɫһ�£�����Ļ�������ǣ��ʶ���ʧ��
//					if(x==0)
//					{
//						setfillcolor(WHITE);
//						setcolor(WHITE);
//						fillcircle(0,y,10);
//
//					}
//					
//				} 
//				
//				//getchar();//�������Ϊ���˳���ԭ��������ԭ����
//			} 
//	}
//
//}


//��������������������cleardevice()��ȱ�㣬����ֻ�к�ɫ�������񷽰�һͨ��bar���Զ��屳����ɫ��
//
//void main()
//{
//	int width = 480;
//	int height = 300;
//	initgraph(width,height);//���ô��ڴ�С
//
//	int x,y;
//	int x1;
//	float t,k;
//
//	while(1)
//	{		
//		for(x1=width;x1>0;x1=x1-5)//����ѭ��
//		{ 
//			cleardevice();
//			setcolor(BLUE); 
//			line(0,150,480,150);
//			
//			k=2*3.1415926/width*x1;
//	
//			for(x=0;x<=width;x++) //��һ����������
//			{
//				
//				t=2*3.1415926/width*x+k;
//				y=(int)(120*sin(t))+height/2;//���߷���
//				putpixel(x,y,GREEN);
//
//				if(x==0)
//				{
//					setfillcolor(RED);
//					solidcircle(0,y,10);
//									
//				}					
//			} 
//			Sleep(30);
//		} 
//	}
//
//}

//system("cls");	//��ʵsystem(��cls��) ������ ���Է�Ϊ���������	
					//�������С�ڿ����еĻ����������þ���������������easyx,����//�������С�ڿ����еĻ����������þ���������������easyx,����
					//���ÿ������Ϊsleep(time) ,���ǻ�������á�
	

int width  = 480;
int height = 380;
//int x[5];
//int y[5];
//int vx[5];
//int vy[5];
//int radius[5];

struct Ball
{
	float x,y;
	float vx,vy;
	float radius;
	
};

Ball balls[10];

void startup()
{
	
	initgraph(width,height);
	BeginBatchDraw();
	srand((unsigned)time(NULL));  

	for(int i=0;i<10;i++)
	{
		balls[i].x = rand()%width;
		balls[i].y = rand()%height;
		balls[i].vx = rand()%5+5;
		balls[i].vy = rand()%5+5;
		balls[i].radius = rand()%15+10;	
	}
}
void show()
{ 

	cleardevice();
	for(int i=0;i<10;i++)
		{
			solidcircle(balls[i].x ,balls[i].y,balls[i].radius);

		}	
	FlushBatchDraw();
	Sleep(20);
}

void update()
{
	
	for(int i=0;i<10;i++)
		{
			balls[i].x  += balls[i].vx;
			balls[i].y  += balls[i].vy;
				
			if(balls[i].x <= balls[i].radius ||balls[i].x >= height-balls[i].radius )				
				balls[i].vx  = -balls[i].vx ;

			if(	balls[i].y  <= balls[i].radius ||balls[i].y >= width-balls[i].radius )
				balls[i].vy  = -balls[i].vy;	
		}

}

int main()
{
	//int n = 0;
	//Ball* balls;

	//printf("������С�������:>");
	//scanf("%d",&n);
	//balls = (Ball*)malloc(n*sizeof(Ball));	

	startup();
	while(1)
	{
		show();
		update();	
	}


	return 0;

}
