#define _CRT_SECURE_NO_WARNINGS 1
/*
* 希尔排序思想：
* 类似插入排序，但在插入排序的基础上进行了改进
* 希尔排序将数组中间隔为gap的数分为一组，然后对它们进行插入排序，这一步叫做预排序
* 当最终gap为1时，就是纯粹的插入排序，但是效率很高
* 因为经过几轮预排序，整个数组几乎处于小的在前，大的在后的状态，因此最后一轮只需要接近O(N)的时间复杂度
* 
* 希尔排序的时间复杂度：n为某一特定范围时，为O(n^1.3)，对于所有n，为O(n^1.3)~O(n^2)
*/
void ShellSort(int* a, int n)
{
	int gap = n;
	int end = 0;
	while (gap > 1)//第一层循环控制gap的大小
	{
		gap = (gap / 3) + 1;
		for (int i = 0; i < n - gap; ++i)//第二层循环控制预排序
		{
			int end = i;
			int insert = a[end + gap];//将end+gap位置的元素插入到end之前的、间隔为gap的一组有序数列（插入排序）
			while (end >= 0)
			{
				if (a[end] > insert)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = insert;
		}
	}
}