#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>

//结构体
//char int double
//

struct Book
{
  char name[20];//C语言程序设计
  short price;//55

};

int main()
{
	//利用结构体类型 创建一个该类型的结构体变量
	struct Book b1 = {"C语言程序设计",55};
    struct Book* pb = &b1;
	strcpy(b1.name,"C++");// 该书名 strcpy - string copy - 字符串拷贝 - 库函数 - string.h 
	//printf("%p",pb);
	printf("书名：%s 价格：%d\n",(*pb).name,(*pb).price);
	printf("书名：%s 价格：%d\n",pb->name,pb->price);

	// .   结构体变量.成员
	// ->  结构体指针->成员
	//printf("书名：%s\n",b1.name);
	//printf("价格：%d\n",b1.price);
	//b1.price = 15;
	//printf("修改后的价格：%d\n",b1.price);
    

	return 0;
}



//指针
//先弄清楚内存概念
//32位电脑  和 64位电脑  32位表示电脑有32个地址线/数据线

//指针类型：  int* 整数型指针变量   char* 字符型指针变量


//
//int main()
//
//{
//	printf("%d\n",sizeof(char*));
//	printf("%d\n",sizeof(int*));
//	printf("%d\n",sizeof(long*));
//	printf("%d\n",sizeof(float*));
//	printf("%d\n",sizeof(double*));
//	printf("%d\n",sizeof(short*));
//
//
//   return 0;
//}


//int main()
//{
//   char ch = 'g';
//   char* pc = &ch;
//   *pc = 'W';
//   printf("ch = %c\n",ch);
//
//   return 0;
//}



//int main()
//{
//	int a = 10;
//	int* p = &a;//取地址a
//	printf("%p\n",p);
//	//有一种变量是用来存在地址的 - 指针变量
//	printf("%p\n",&a);
//	*p = 2012;// 解引用操作符  或者 间接访问操作符
//	printf("a = %d\n",a);
//
//
//
//
//   return 0;
//}





////#define 定义标识符常量
////#define MAX 100
////#define 可以定义宏  带参数
//
////函数实现大小比较
//int Max(int x, int y)
//{
//    if (x > y)
//		return x;
//	else
//		return y;
//}
//
////用宏的方式实现两个数的大小比较
//
//#define MAX(a,b)(a>b?a:b)
//
//int main()
//{
//   int a =10;
//   int b =20;
//   int max =0;
//   //int max2 =0;
//   //函数方式
//   max = Max(a,b);
//   printf("max = %d\n",max);
//   //宏方式实现
//   max = MAX(a,b);
//	printf("max = %d\n",max);
//
//}

////声明外部函数
//extern int Add(int ,int);
//int main()
//{
//	int a =10;
//	int b =20;
//	int sum = Add(a,b);
//	printf("sum = %d\n",sum);
//
//
//    return 0;
//
//}




//static 修饰局部变量，局部周期变长
//static 修饰全部变量, 改变了变量的作用域，让静态的全局变量只能在自己所在的源文件内部使用，出了源文件就不能使用了
//static 修饰函数，改变了函数的链接属性   由外部链接属性  -->  内部链接属性

//int a = 0;
//int main()
//{
//	//extern  声明外部符号的
//	extern int g_val;
//	printf("g_val=%d\n",g_val);
//
//    return 0;
//}




//void test()
//{
//   static int a =1;//a是一个静态的局部变量
//   a++;
//   printf("a = %d\n",a);//2 3 4 5 6
//}
//
//
//int main()
//{
//	int i =0;
//	while(i<5)
//	{
//	  test();
//	  i++;
//	}
//    return 0;
//}


//int main()
//{
//   //typedef - 类型定义 类型重定义
//	unsigned int num = 10;
//	typedef unsigned int u_int;
//	u_int num2 = 20;
//
//	return 0;
//
//}





//关键字
//int main()
//
//{
//   //register int a = 10;//reguster 是寄存器变量 建议将变量a放在寄存器中，实际是否放由编译器决定。
//   //int 定义的变量是有符号的 = signed int
//   //unsigned int 是无符号整型
//   //struct  结构体关键字
//   //union  联合体/共用体
//   //volatile 
//
//
//   return 0;
//}






//int main()
//
//{
//   auto int a =10;//局部变量也叫自动变量
//
//   return 0;
//}













//int Add(int x, int y)
//{
//  int z = x + y;
//  return z;
//
//}
//
//
//int main()
//
//{
//	//int arr[10] = {0};
//    //arr[4];//[] - 下标引用操作符
//    int a = 0;
//	int b = 0;
//	int sum = 0;
//	printf("请输入a和b的值：\n");
//	scanf("%d%d",&a,&b);
//	sum = Add(a,b);//() -- 函数调用操作符
//	printf("sum = %d\n",sum);
//    return 0;
//}







////条件操作符/三目操作符
//int main()
//{
//  int a = 100;
//  int b = 20;
//  int max = 0;
//
//  max = (a>b ? a : b);
//  //if (a>b)
//	 // max = a;
//  //else 
//	 // max = b;
//  printf("max = %d\n",max);
//  return 0; 
//}












//while 循环语句示例
//int main()
//{
//	int line = 0;
//	printf("加入比特\n");
//	while(line < 20000)
//	{
//	  printf("敲一行代码:%d\n",line);
//	  line++;
//	
//	}
//	if(line>=20000)
//	   printf("好offer！\n");
//
//
//   return 0;
//}








//int main()
//{
//  int input = 0;
//  printf("加入启航科技\n");
//  printf("你要好好学习吗？（1、0）>:\n");
//  scanf("%d",&input);
//	  if(input==1)
//		  printf("好Offer！\n");
//	  else
//		  printf("卖红薯\n");
//
//  return 0;
//}

//int main()
//{
//  printf("(are you ok??)\n");
//	printf("%c\n",'\x30');
//  printf("g:\\10-c语言学习\\鹏哥c教程\\test 10-04\\test 10-04\\test.c\n");
//  printf("%d\n",strlen("c:\\test\32\\test.c"));
//  return 0;
//}



//int main()
//{
//   float num1=0;
//   float num2=0;
//   float sum=0;
//   scanf("%f%f",&num1,&num2);
//   sum = num1 + num2;
//   printf("sum = %f\n",sum);
//   getchar();
//   return 0;
//
//}

//int Add(int x,int y)
//{
//   int z = x + y;
//   return z;
//}
//
//int main()
//{
//  int a=0; 
//  int b=0;
//  int sum=0;
//  printf("请输入两个整数进行相加\n");
//  scanf("%d%d",&a,&b);
//  sum = Add(a,b);
//  printf("sum = %d\n",sum);
//}


//int main()
//{   
//	//数据在计算机上存储的时候，存储的是二进制
//	//#av$
//	//a - 97
//	//A - 65
//	//...
//	//ASCII 编码
//	//ASCII 码值
//    char arr1[]="abc";//'\0'是结束标志，隐藏在最后一位
//	char arr2[]={'a','b','c','\0'};//最后补0或者'\0';
//	printf("%d\n",strlen(arr1));//3  字符串长度
//	printf("%d\n",strlen(arr2));//3 
//	//printf("%s\n",arr1);						
//	//printf("%s\n",arr2);
//    return 0;
//}

//int main()
//{
//	int i =0;
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
//	while(i<=9)
//	{
//	  printf("%d\n",arr[i]);
//	  i++;
//	}
//
//
//  return 0;
//}


//移位操作符
//int main()
//
//{
//	int a = 1;//二进制表示为00000000000000000000000000000001  1个字节32bit位（内存空间）
//	int b;
//	b = a<<5;
//	printf("b = %d\n",b);
//	printf("a = %d\n",a);
//    return 0;
//
//}

//int main()
//{
//  //(2进制)位操作
//  //& 按位与  有一位是假即为假，两个都为真时为真；
//  //| 按位或  有一个真即为真；
//  //^ 按位异或   计算规律是对应的二进制位相同则位0，对应的二进制位相异则为1；
//
//	int a = 11; //二进制表示为1011
//	int b = 4; //             0100
//	int c = a & b;// c=       0000 
//	int d = a | b;// d=       1111 
//	int e = a ^ b;// e=       1111
//	  
//	printf("c = %d\n",c);//0
//	printf("d = %d\n",d);//15
//	printf("e = %d\n",e);//15
//
//	return 0;
//}


//int main()
//
//{
//	int a = 0;//4个字节，32个bit位
//	int b = ~a;//b是有符号的整型
//	//~   按位（二进制位）取反
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111

//	//原码  反码  补码
//	//负数在内存中存储的时候，存储的是二进制的补码
//	//二进制最高位是符号位，1是负号 0是正号
//	printf("%d\n",b);//打印的是这个数的原码

//  只要是整数，内存中存储的都是二进制补码
//  正数 --- 原码 反码 补码 三码相同
//  负数: 存的是补码
//  原码            ----->           反码          ------>                   补码
//  直接按照正负写出二进制序列       原码的符号位不变，其它位按位取反        反码+1
 


//	//补码-->原码过程如下：
//	//补码                   11111111111111111111111111111111
//	//反码-1                 11111111111111111111111111111110
//	//原码取反（符号位不变） 10000000000000000000000000000001  结果是-1
//    
//	//原码-->补码过程如下：
//	//原码                        10000000000000000000000000000001
//	//反码（符号位不变，其它取反）11111111111111111111111111111110
//	//补码 +1                     11111111111111111111111111111111
//
//
//	return 0;
//
//}


//int main()
//
//{
//	int a = 10;
//	//int b = a++;// 后置++，先使用a赋值给b，然后再++；a=11 b=10
//	//int b = ++a;//前置++，a先++，然后赋值给b；a=11 b=11
//	//int b = a--;//a=9 b=10
//	//int b = --a;//a=9 b=9
//	printf("a=%d,b=%d\n",a,b);
//    return 0;
//}

//int main()
//
//{
//   int a = (int)3.14; // (int) 表示3.14强制转换为整型
//   printf("a=%d\n",a);
//   return 0;
//
//}

//int main()
//
//{
//	//真  非0
//    //假   0
//	//&&  逻辑与
//	//||  逻辑或
//	int a =3;
//	int b =0;
//	//int c =a && b;
//	int c =a || b;
//	printf("c= %d\n",c);
//
//   return 0;
//}

