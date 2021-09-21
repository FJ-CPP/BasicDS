#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap(int* x, int* y);
void adjustDown(int* a, int parent, int n)//建大堆向下调整算法
{
	int child = 2 * parent + 1;//默认child为parent的左孩子
	while (child < n)//child实际为数组元素的下标，如果其存在，则child < n
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;//如果右孩子大于左孩子，那么让右孩子和parent比较
		}
		if (a[child] > a[parent])
		{
			swap(&a[parent], &a[child]);//child>parent，此时需要交换它们并让child成为下一次的parent
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;//如果parent>=child，说明此时不再需要调整（调整的前提是左右子树都是小堆或大堆）
		}
	}
	//时间复杂度为O(logn)
	//分析：将根元素向下调整，最多执行树的深度次
}
void heapSort(int* a, int n)//按升序进行堆排序
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)//建堆，从最后一个叶子节点的父节点开始调整，直到整棵树满足大堆性质
	{
		adjustDown(a, i, n);
		//建堆的时间复杂度为O(n)
		/*
		分析：
		考虑最坏的情况，则假设堆为满二叉树，高度为h。
		假设层数为i(i∈[1,h])，则第i层节点数为2^(i-1）
		满二叉树建堆是从最后一个非叶子节点开始调整
		即先调整第h-1层，再调整第h-2层...最后调整第1层
		每一层的节点，最坏情况下会向下调整h-i次
		因此，时间复杂度 T = 2^0*(h-1) + 2^1*(h-2) + ... + 2^(h-2)*1
		              2*T = 2^1*(h-1) + 2^2*(h-2) + ... + 2^(h-1)*1
		通过错位相消，得到T = 2^1 + 2^2 + ... + 2^(h-2) +2^(h-1)*1 - 2^0*(h-1) = 2^h - h - 1
		而节点总数n = 2^h - 1,h = log(n+1)
		因此T = n - log(n+1)
		用大O渐进表示法为O(n)
		*/
	}
	int end = n;
	while (end > 0)
	{
		swap(&a[0], &a[end - 1]);//交换根元素和最后一个元素，使当前最大的数排在数组的最后
		--end;//让下一次调整的下限-1，即交换到后面的元素不再参与下一次的向下调整
		adjustDown(a, 0, end);
	}
}
int main()
{
	//int arr[] = { 23,47,55,16,8,31,25,66,48,51,14,73,81,99 };
	int arr[] = { 5,2,3,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, sz);
	for (size_t i = 0; i < sz; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}