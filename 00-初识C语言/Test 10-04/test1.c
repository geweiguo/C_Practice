#define _CRT_SECURE_NO_WARNINGS 1 
#include<stdio.h>
#include<string.h>

//�ṹ��
//char int double
//

struct Book
{
  char name[20];//C���Գ������
  short price;//55

};

int main()
{
	//���ýṹ������ ����һ�������͵Ľṹ�����
	struct Book b1 = {"C���Գ������",55};
    struct Book* pb = &b1;
	strcpy(b1.name,"C++");// ������ strcpy - string copy - �ַ������� - �⺯�� - string.h 
	//printf("%p",pb);
	printf("������%s �۸�%d\n",(*pb).name,(*pb).price);
	printf("������%s �۸�%d\n",pb->name,pb->price);

	// .   �ṹ�����.��Ա
	// ->  �ṹ��ָ��->��Ա
	//printf("������%s\n",b1.name);
	//printf("�۸�%d\n",b1.price);
	//b1.price = 15;
	//printf("�޸ĺ�ļ۸�%d\n",b1.price);
    

	return 0;
}



//ָ��
//��Ū����ڴ����
//32λ����  �� 64λ����  32λ��ʾ������32����ַ��/������

//ָ�����ͣ�  int* ������ָ�����   char* �ַ���ָ�����


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
//	int* p = &a;//ȡ��ַa
//	printf("%p\n",p);
//	//��һ�ֱ������������ڵ�ַ�� - ָ�����
//	printf("%p\n",&a);
//	*p = 2012;// �����ò�����  ���� ��ӷ��ʲ�����
//	printf("a = %d\n",a);
//
//
//
//
//   return 0;
//}





////#define �����ʶ������
////#define MAX 100
////#define ���Զ����  ������
//
////����ʵ�ִ�С�Ƚ�
//int Max(int x, int y)
//{
//    if (x > y)
//		return x;
//	else
//		return y;
//}
//
////�ú�ķ�ʽʵ���������Ĵ�С�Ƚ�
//
//#define MAX(a,b)(a>b?a:b)
//
//int main()
//{
//   int a =10;
//   int b =20;
//   int max =0;
//   //int max2 =0;
//   //������ʽ
//   max = Max(a,b);
//   printf("max = %d\n",max);
//   //�귽ʽʵ��
//   max = MAX(a,b);
//	printf("max = %d\n",max);
//
//}

////�����ⲿ����
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




//static ���ξֲ��������ֲ����ڱ䳤
//static ����ȫ������, �ı��˱������������þ�̬��ȫ�ֱ���ֻ�����Լ����ڵ�Դ�ļ��ڲ�ʹ�ã�����Դ�ļ��Ͳ���ʹ����
//static ���κ������ı��˺�������������   ���ⲿ��������  -->  �ڲ���������

//int a = 0;
//int main()
//{
//	//extern  �����ⲿ���ŵ�
//	extern int g_val;
//	printf("g_val=%d\n",g_val);
//
//    return 0;
//}




//void test()
//{
//   static int a =1;//a��һ����̬�ľֲ�����
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
//   //typedef - ���Ͷ��� �����ض���
//	unsigned int num = 10;
//	typedef unsigned int u_int;
//	u_int num2 = 20;
//
//	return 0;
//
//}





//�ؼ���
//int main()
//
//{
//   //register int a = 10;//reguster �ǼĴ������� ���齫����a���ڼĴ����У�ʵ���Ƿ���ɱ�����������
//   //int ����ı������з��ŵ� = signed int
//   //unsigned int ���޷�������
//   //struct  �ṹ��ؼ���
//   //union  ������/������
//   //volatile 
//
//
//   return 0;
//}






//int main()
//
//{
//   auto int a =10;//�ֲ�����Ҳ���Զ�����
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
//    //arr[4];//[] - �±����ò�����
//    int a = 0;
//	int b = 0;
//	int sum = 0;
//	printf("������a��b��ֵ��\n");
//	scanf("%d%d",&a,&b);
//	sum = Add(a,b);//() -- �������ò�����
//	printf("sum = %d\n",sum);
//    return 0;
//}







////����������/��Ŀ������
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












//while ѭ�����ʾ��
//int main()
//{
//	int line = 0;
//	printf("�������\n");
//	while(line < 20000)
//	{
//	  printf("��һ�д���:%d\n",line);
//	  line++;
//	
//	}
//	if(line>=20000)
//	   printf("��offer��\n");
//
//
//   return 0;
//}








//int main()
//{
//  int input = 0;
//  printf("���������Ƽ�\n");
//  printf("��Ҫ�ú�ѧϰ�𣿣�1��0��>:\n");
//  scanf("%d",&input);
//	  if(input==1)
//		  printf("��Offer��\n");
//	  else
//		  printf("������\n");
//
//  return 0;
//}

//int main()
//{
//  printf("(are you ok??)\n");
//	printf("%c\n",'\x30');
//  printf("g:\\10-c����ѧϰ\\����c�̳�\\test 10-04\\test 10-04\\test.c\n");
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
//  printf("���������������������\n");
//  scanf("%d%d",&a,&b);
//  sum = Add(a,b);
//  printf("sum = %d\n",sum);
//}


//int main()
//{   
//	//�����ڼ�����ϴ洢��ʱ�򣬴洢���Ƕ�����
//	//#av$
//	//a - 97
//	//A - 65
//	//...
//	//ASCII ����
//	//ASCII ��ֵ
//    char arr1[]="abc";//'\0'�ǽ�����־�����������һλ
//	char arr2[]={'a','b','c','\0'};//���0����'\0';
//	printf("%d\n",strlen(arr1));//3  �ַ�������
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


//��λ������
//int main()
//
//{
//	int a = 1;//�����Ʊ�ʾΪ00000000000000000000000000000001  1���ֽ�32bitλ���ڴ�ռ䣩
//	int b;
//	b = a<<5;
//	printf("b = %d\n",b);
//	printf("a = %d\n",a);
//    return 0;
//
//}

//int main()
//{
//  //(2����)λ����
//  //& ��λ��  ��һλ�Ǽټ�Ϊ�٣�������Ϊ��ʱΪ�棻
//  //| ��λ��  ��һ���漴Ϊ�棻
//  //^ ��λ���   ��������Ƕ�Ӧ�Ķ�����λ��ͬ��λ0����Ӧ�Ķ�����λ������Ϊ1��
//
//	int a = 11; //�����Ʊ�ʾΪ1011
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
//	int a = 0;//4���ֽڣ�32��bitλ
//	int b = ~a;//b���з��ŵ�����
//	//~   ��λ��������λ��ȡ��
//	//00000000000000000000000000000000
//	//11111111111111111111111111111111

//	//ԭ��  ����  ����
//	//�������ڴ��д洢��ʱ�򣬴洢���Ƕ����ƵĲ���
//	//���������λ�Ƿ���λ��1�Ǹ��� 0������
//	printf("%d\n",b);//��ӡ�����������ԭ��

//  ֻҪ���������ڴ��д洢�Ķ��Ƕ����Ʋ���
//  ���� --- ԭ�� ���� ���� ������ͬ
//  ����: ����ǲ���
//  ԭ��            ----->           ����          ------>                   ����
//  ֱ�Ӱ�������д������������       ԭ��ķ���λ���䣬����λ��λȡ��        ����+1
 


//	//����-->ԭ��������£�
//	//����                   11111111111111111111111111111111
//	//����-1                 11111111111111111111111111111110
//	//ԭ��ȡ��������λ���䣩 10000000000000000000000000000001  �����-1
//    
//	//ԭ��-->����������£�
//	//ԭ��                        10000000000000000000000000000001
//	//���루����λ���䣬����ȡ����11111111111111111111111111111110
//	//���� +1                     11111111111111111111111111111111
//
//
//	return 0;
//
//}


//int main()
//
//{
//	int a = 10;
//	//int b = a++;// ����++����ʹ��a��ֵ��b��Ȼ����++��a=11 b=10
//	//int b = ++a;//ǰ��++��a��++��Ȼ��ֵ��b��a=11 b=11
//	//int b = a--;//a=9 b=10
//	//int b = --a;//a=9 b=9
//	printf("a=%d,b=%d\n",a,b);
//    return 0;
//}

//int main()
//
//{
//   int a = (int)3.14; // (int) ��ʾ3.14ǿ��ת��Ϊ����
//   printf("a=%d\n",a);
//   return 0;
//
//}

//int main()
//
//{
//	//��  ��0
//    //��   0
//	//&&  �߼���
//	//||  �߼���
//	int a =3;
//	int b =0;
//	//int c =a && b;
//	int c =a || b;
//	printf("c= %d\n",c);
//
//   return 0;
//}

