#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
/*
* 计数排序原理：
* 根据数组中数字的范围开辟一个count数组，大小为range（range = 最大值-最小值+1）
* 数组中每一个元素与最小值的差值都能在count中找到唯一的映射，称为相对映射
* 根据count某个位置的值就可以确定它映射的数是多少，以及出现了多少次。
* 
* 时间复杂度：O(n + range)
* 空间复杂度：O(range)
*/
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];//找到数组元素的最大值和最小值
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;//计算相对映射数组的大小
	int* count = (int*)malloc(sizeof(int) * range);
	if (count == NULL)
		exit(-1);
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;//相对映射
	}
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;
		}
	}
	free(count);
}