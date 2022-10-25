#include<stdio.h>
#include<graphics.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
//以下是正弦函数曲线 两个方案
//方案一：分两次画曲线，第一次为绿色；第二次为白色与背景颜色白色一致；从而达到覆盖上一次绿色效果；
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
//	  //cleardevice();//此条语句为检测此程序原理，不属于原程序。屏幕颜色清除后为黑色。
//		for(x1=0;x1>-480;x1--)
//			{
//				k=2*3.1415926/480*x1;
//				for(x=0;x<=480;x++)
//				{
//					t=2*3.1415926/480*x+k;
//					y=-(int)(100*sin(t))+160; 
//					putpixel(x,y,GREEN); //第一次曲线颜色为GREEN；
//						if(x==0)
//						{
//							setfillcolor(RED);
//							fillcircle(0,y,10);
//						}
//					setcolor(BLACK);
//					line(0,160,480,160);
//				} 
//
//				//getchar();//此条语句为检测此程序原理，不属于原程序。
//
//				for(x=0;x<=480;x++)
//				{
//					t=2*3.1415926/480*x+k;
//					y=-(int)(100*sin(t))+160;
//					putpixel(x,y,WHITE);//第二次曲线用于清除第一次曲线；原理：颜色为WHITE，与背景颜色一致，被屏幕背景覆盖，故而消失。
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
//				//getchar();//此条语句为检测此程序原理，不属于原程序。
//			} 
//	}
//
//}


//方案二：利用清屏函数cleardevice()；缺点，背景只有黑色，不能像方案一通过bar来自定义背景颜色；
//
//void main()
//{
//	int width = 480;
//	int height = 300;
//	initgraph(width,height);//设置窗口大小
//
//	int x,y;
//	int x1;
//	float t,k;
//
//	while(1)
//	{		
//		for(x1=width;x1>0;x1=x1-5)//曲线循环
//		{ 
//			cleardevice();
//			setcolor(BLUE); 
//			line(0,150,480,150);
//			
//			k=2*3.1415926/width*x1;
//	
//			for(x=0;x<=width;x++) //画一幅正弦曲线
//			{
//				
//				t=2*3.1415926/width*x+k;
//				y=(int)(120*sin(t))+height/2;//曲线方程
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

//system("cls");	//其实system(“cls”) 的作用 可以分为俩种情况，	
					//如果是在小黑框运行的话，它的作用就是清屏，如果结合easyx,它的//如果是在小黑框运行的话，它的作用就是清屏，如果结合easyx,它的
					//作用可以理解为sleep(time) ,就是缓存的作用。
	

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

	//printf("请输入小球的数量:>");
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
