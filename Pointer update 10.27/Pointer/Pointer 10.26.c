
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//qsort() ������ʹ�ã����Զ������������ݽ�������
struct stu
{
	char name[20];
	int age;
};
int cmp_s_byname(const void*e1 ,const void* e2)
{
	return strcmp(((struct stu*)e2)->name,((struct stu*)e1)->name);

}
int main()
{
	int i = 0;
	struct stu s[7] = { {"zhangsan",20} ,
							{"Wujing",35}, 
							{"Changhong",55},
							{"Tieqiu",15} ,
							{"Xiaoming",15} ,
							{"Ahong",15} ,
							{"Bingge",15} 
						};
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s,sz, sizeof(s[0]),cmp_s_byname);
	
	for (i = 0; i < 7; i++)
	{
		printf("%-10s %2d \n\n", s[i].name, s[i].age);
	}

	return 0;
}


//
//void print(char* str)
//{
//	printf("%s",str);
//}
//
//int main()
//{
//	void (*pa)(char*) = print;
//	print("hello Greg��"); 
//	(*pa)("hello Greg��");
//	return 0;
//}

//
//void printf1(int arr[3][5],int x,int y)
//{
//	int i = 0;
//	for(i=0; i<x ; i++)
//	{
//		int j = 0;
//		for(j=0;j<y;j++)
//		{
//			printf("%d ",arr[i][j]);
//	
//		}
//		printf("\n");
//	}
//
//}
//void printf2(int (*p)[5],int x,int y)//��ά���鴫��ַ��ָ�����ʱ��������Ԫ�صĵ�ַ��
//{
//	int i = 0;
//	for(i=0; i<x ; i++)
//	{
//		int j = 0;
//		for(j=0;j<y;j++)
//		{
//			printf("%d ",p[i][j]);
//	
//		}
//		printf("\n");
//	}
//
//
//}
//
//
//int main()
//{
//	int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};//��Ԫ����{1,2,3,4,5}
//
//	printf1(arr,3,5); 
//	printf2(arr,3,5);
//
//	return 0;
//
//}






//����������ָ��
//int main()
//{
//	int i =0;
//
//	int arr1[5] = {9,8,7,6,5};
//	int (*p)[5] = &arr1;//&arr ��ʾ��������ĵ�ַ����������Ԫ�صĵ�ַ��
//	
//	for(i=0;i<5;i++)
//	{
//		printf("%d \n",*((*p)+i));	//���������е�ÿ��Ԫ��
//		printf("%d \n",(arr1[i]));//���������е�ÿ��Ԫ��
//		printf("%p \n",((*p)+i));	//����ÿ��Ԫ�صĵ�ַ
//		printf("%p \n",((arr1)+i));	//����ÿ��Ԫ�صĵ�ַ
//		printf("%p \n",((&arr1)+i));//����arr1�ĵ�ַ�����һ������Ĵ�С��20���ֽڣ�
//
//	}
//	printf("%d \n",sizeof(arr1));//20���ֽ�
//	
//
//	printf("\n");
//	
//	return 0 ;
//}

//������ָ������
//int main()
//{
//	int i = 0;
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = {2,3,4,5,6};
//	int arr3[] = {3,4,5,6,7};
//
//	int* parr[] = {arr1,arr2,arr3}; //�����ָ�����飬���������飻
//
//	for(i=0;i<3;i++)
//	{
//		int j = 0;
//		for(j=0;j<5;j++)
//		{
//			printf("%d ",*(parr[i]+j));		
//		}
//		printf("\n");
//	
//	}
//	return 0 ;
//}