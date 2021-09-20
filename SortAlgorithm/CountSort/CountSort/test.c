#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 30
void CountSort(int* a, int n);
int main()
{
	srand((unsigned int)time(0));
	int* a = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N; ++i)
	{
		a[i] = rand() % 100;
	}
	int begin = clock();
	CountSort(a, N);
	int end = clock();
	for (int i = 0; i < N; ++i)
	{
		printf("%d ", a[i]);
	}
	int flag = 1;
	for (int i = 1; i < N; ++i)
	{
		if (a[i] < a[i - 1])
		{
			flag = 0;
			break;
		}
	}
	printf("\n");
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