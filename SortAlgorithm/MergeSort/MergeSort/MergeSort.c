#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
/*
* 归并排序思想：分治
* 归并是将左右两个有序数组合并成一个。
* 而为了得到有序数组，还要将它们二分，然后再合并它们的左右两个有序数组
* 类似于二叉树的后序遍历。先执行左右数组的排序，再执行原数组的合并工作
* 排序借助一个能存放n个元素的新数组。
* 待排序的数组有一个下标范围，而排序操作就在新数组对应的范围内进行，然后再拷贝回原来的数组
* 
* 时间复杂度：O(NlogN)
* 空间复杂度：O(N)
*/

//递归法
void merge(int* a, int* tmp, int begin1, int end1, int begin2, int end2)
{
	int i = begin1;
	int left = begin1;//保存归并后tmp拷贝到a的范围
	int right = end2;
	while (begin1 <= end1 && begin2 <= end2)//对已经排序好的左右两个数组进行归并(双指针法)
	{
		if (a[begin1] < a[begin2])//由于归并的元素范围是[left,right]，因此它们也要存放在tmp中的[left,right]范围内
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	//将有剩余的数组中的元素继续追加到tmp中
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	for (int j = left; j <= right; ++j)//将tmp中[left,right]范围内的元素拷贝到新数组
	{
		a[j] = tmp[j];
	}
}
void _mergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
	{
		return;//只有一个元素，已是有序数组
	}
	int mid = (left + right) >> 1;//将数组分成[left,mid]和[mid+1,right]两份
	_mergeSort(a, left, mid, tmp);//将[left,mid]排序
	_mergeSort(a, mid + 1, right, tmp);//将[mid+1,right]排序

	merge(a, tmp, left, mid, mid + 1, right);//将[left,mid]和[mid+1,right]归并到a中

}
void mergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}
	else
	{
		_mergeSort(a, 0, n - 1, tmp);
	}
	free(tmp);
}

//迭代法
void mergeSort_iterate(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		exit(-1);
	}
	int gap = 1;//控制归并时每一组的元素个数
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			//将[i, i + gap - 1]和[i + gap, i + 2 * gap -1]归并
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = i + gap;
			int end2 = i + 2 * gap - 1;
			//特殊情况考虑
			//1、左区间只有一部分或者右区间完全不存在的情况，无需归并
			if (i + gap - 1 >= n)
				break;
			//2、右区间只有一部分，则修正end2
			if (end2 >= n)
				end2 = n - 1;
			merge(a, tmp, begin1, end1, begin2, end2);//归并
		}
		gap *= 2;
	}
	free(tmp);
}