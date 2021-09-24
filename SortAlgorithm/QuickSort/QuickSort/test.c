#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int* x, int* y);
void quickSort(int* a, int begin, int end);
void quickSort_plus(int* a, int begin, int end);
void quickSort_iterate(int* a, int n);
#define N 30

int main()
{
	srand((unsigned int)time(0));
	int* a = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)//数组插入随机数
	{
		a[i] = rand() % 100;
	}
	int begin = clock();
	quickSort_iterate(a, 0, N - 1);//排序
	int end = clock();
	for (int i = 0; i < N; ++i)//打印数组
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int flag = 1;
	for (int i = 1; i < N; ++i)//判断是否有序
	{
		if (a[i] < a[i - 1])
		{
			flag = 0;
			break;
		}
	}
	
	if (flag == 1)
	{
		printf("sorting success!\nUsing Time:%dms\n", end - begin);
	}
	else
	{
		printf("sorting failed!\n");
	}
	return 0;
}