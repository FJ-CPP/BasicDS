#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
static void adjustDown(int* a, int parent, int n)//建小堆向下调整算法
{
	int child = 2 * parent + 1;//默认child为parent的左孩子
	while (child < n)//child实际为数组元素的下标，如果其存在，则child < n
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			++child;//如果右孩子小于左孩子，那么让右孩子和parent比较
		}
		if (a[child] < a[parent])
		{
			swap(&a[parent], &a[child]);//child<parent，此时需要交换它们并让child成为下一次的parent
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;//如果parent<=child，说明此时不再需要调整（调整的前提是左右子树都是小堆或大堆）
		}
	}
	//时间复杂度为O(logn)
	//分析：将根元素向下调整，最多执行树的深度次
}
//int main()
//{
//	int arr[] = { 23,47,16,48,51,17,22 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	adjustDown(arr, 0, sz);//建小堆
//	return 0;
//}