
#include<stdio.h>

void printf1(int arr[3][5],int x,int y)
{
	int i = 0;
	for(i=0; i<x ; i++)
	{
		int j = 0;
		for(j=0;j<y;j++)
		{
			printf("%d ",arr[i][j]);
	
		}
		printf("\n");
	}

}
void printf2(int (*p)[5],int x,int y)//二维数组传地址，指针接收时是数组首元素的地址；
{
	int i = 0;
	for(i=0; i<x ; i++)
	{
		int j = 0;
		for(j=0;j<y;j++)
		{
			printf("%d ",p[i][j]);
	
		}
		printf("\n");
	}


}


int main()
{
	int arr[3][5] = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7}};//首元素是{1,2,3,4,5}

	printf1(arr,3,5); 
	printf2(arr,3,5);

	return 0;

}






//以下是数组指针
//int main()
//{
//	int i =0;
//
//	int arr1[5] = {9,8,7,6,5};
//	int (*p)[5] = &arr1;//&arr 表示的是数组的地址，而不是首元素的地址；
//	
//	for(i=0;i<5;i++)
//	{
//		printf("%d \n",*((*p)+i));	//遍历数组中的每个元素
//		printf("%d \n",(arr1[i]));//遍历数组中的每个元素
//		printf("%p \n",((*p)+i));	//遍历每个元素的地址
//		printf("%p \n",((arr1)+i));	//遍历每个元素的地址
//		printf("%p \n",((&arr1)+i));//数组arr1的地址向后跳一个数组的大小（20个字节）
//
//	}
//	printf("%d \n",sizeof(arr1));//20个字节
//	
//
//	printf("\n");
//	
//	return 0 ;
//}

//以下是指针数组
//int main()
//{
//	int i = 0;
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = {2,3,4,5,6};
//	int arr3[] = {3,4,5,6,7};
//
//	int* parr[] = {arr1,arr2,arr3}; //这个是指针数组，本质是数组；
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