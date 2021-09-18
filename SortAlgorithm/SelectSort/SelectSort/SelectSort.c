#define _CRT_SECURE_NO_WARNINGS 1

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* 选择排序思想：
* 找到[left,right]区间内的最大值和最小值，然后将其与left和right交换，达到当前区间内最值在两边的状态
* left和right的初始值为0和n-1，即整个数组的左边界和右边界
* 随着循环的进行，左边界每次向右移一位，右边界每次向左移一位，达到缩小区间的目的，然后再进行选最值和交换
* 
* 时间复杂度:O(N^2)
*/
void SelectSort(int* a, int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		int maxIndex = left, minIndex = left;
		for (int i = left; i <= right; ++i)//找到[left,right]内最大值和最小值的下标
		{
			if (a[i] > a[maxIndex])
			{
				maxIndex = i;
			}
			if (a[i] < a[minIndex])
			{
				minIndex = i;
			}
		}
		swap(&a[left], &a[minIndex]);//将最小值与a[left]交换
		if (left == maxIndex)//防止left是最大值下标的情况下，最大值在上一步被交换到了minIndex的位置，导致下一步交换出错
		{
			maxIndex = minIndex;
		}
		swap(&a[right], &a[maxIndex]);//将最大值与a[right]交换
		++left;
		--right;
	}
}