#define _CRT_SECURE_NO_WARNINGS 1
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* 冒泡排序思想：
* 对于n个数的数组，要进行n-1轮“冒泡”，每一轮将本轮的最值排在最后面的位置
* 上一轮冒泡到最后的数不再参与下一轮冒泡
* 每一轮参与冒泡的数可以看成一个组，而冒泡排序就是将每一组的最值排到最后的位置
* 
* 时间复杂度：最好O(N),最坏O(N^2)
*/
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int flag = 1;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (a[j + 1] < a[j])
			{
				swap(&a[j + 1], &a[j]);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}