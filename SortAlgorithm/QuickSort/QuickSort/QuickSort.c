#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
/*
* 快速排序思想：
* 1、分治算法：每轮排序取一个key值，将小于key的值排在key左边，大于key的排在key右边，然后以key为分界线，再对左、右的数组进行相同的操作。
* 
* 2、迭代算法：类似于分治，但采取的是迭代的方式，用栈保存下次要排序的左右边界，类似于二叉树的层序遍历。
* 时间复杂度：O(NlogN)
* 空间复杂度：O(logN)
*/

//单趟排序算法
//1、Hoare版本（左右指针法）
int hoare_partSort(int* a, int left, int right)
{
	int keyIndex = left;
	while (left < right)
	{
		while (left < right && a[right] >= a[keyIndex])//right向左找小于key的数
		{
			--right;
		}
		while (left < right && a[left] <= a[keyIndex])//left向右找大于key的数
		{
			++left;
		}
		swap(&a[left], &a[right]);//交换a[left]和a[right]
	}
	swap(&a[keyIndex], &a[right]);//最后再将key与a[right]交换（由于right先走，最后终止时，a[right]必然小于key）
	return right;//right即为left和right的相遇点，也是key所在位置
}

//2、挖坑法
int digHole_partSort(int* a, int left, int right)
{
	//将key单独拿出来，此时left成为一个坑位等待数据填充
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		//右边找到一个比key小的数，然后将right填到左边的left坑位中，此时right成为一个坑位等待数据填充
		a[left] = a[right];
		while (left < right && a[left] <= key)
		{
			++left;
		}
		//左边找到一个比key大的数，然后将left填到右边的right坑位中，此时left又称为一个坑位等待数据填充
		a[right] = a[left];
	}
	//left和right相遇，此时将key填充到坑位中(相遇点即为坑位，因为坑位永远是left或right)
	a[right] = key;
	return right;
}

//3、前后指针法
int partSort(int* a, int left, int right)
{
	int slow = left;
	int fast = left + 1;
	int keyIndex = left;
	while (fast <= right)
	{
		if (a[fast] < a[keyIndex] && ++slow != fast)//第二个判断避免一开始fast就小于key，导致slow++后自己跟自己交换
		{
			swap(&a[slow], &a[fast]);
		}
		++fast;
	}
	swap(&a[keyIndex], &a[slow]);
	return slow;
}

//单趟排序优化(避免排序有序数组时算法的时间复杂度退化成O(N^2))
//三数取中法确定key
int getMid(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])//left>mid>right
			return mid;
		else if (a[left] > a[right])//left>right>mid
			return right;
		else//right>left>mid
			return left;
	}
	else//left <= mid
	{
		if (a[mid] < a[right])//right>mid>left
			return mid;
		else if (a[left] < a[right])//mid>right>left
			return right;
		else//mid>left>right
			return left;
	}
}
int digHole_partSort_plus(int* a, int left, int right)
{
	//将key单独拿出来，此时left成为一个坑位等待数据填充
	int keyIndex = getMid(a, left, right);//三数取中法确定key（可能是left/right/mid）
	swap(&a[left], &a[keyIndex]);//始终让最左边的数做key，因此交换a[left]和a[keyIndex]
	while (left < right)
	{
		while (left < right && a[right] >= a[keyIndex])
		{
			--right;
		}
		//右边找到一个比key小的数，然后将right填到左边的left坑位中，此时right成为一个坑位等待数据填充
		a[left] = a[right];
		while (left < right && a[left] <= a[keyIndex])
		{
			++left;
		}
		//左边找到一个比key大的数，然后将left填到右边的right坑位中，此时left又称为一个坑位等待数据填充
		a[right] = a[left];
	}
	//left和right相遇，此时将key填充到坑位中(相遇点即为坑位，因为坑位永远是left或right)
	a[right] = a[keyIndex];
	return right;
}


//快速排序算法
//1、递归法
void quickSort(int* a, int begin, int end)
{
	if (begin >= end)//当该序列只有一个数或没有数的时候，无需排序，直接返回
	{
		return;
	}
	int keyIndex = partSort(a, begin, end);
	//此时经过上面的交换，key的位置确定，只需要递归将key左边和右边的序列进行排序(类似二叉树的前序遍历)
	quickSort(a, begin, keyIndex - 1);
	quickSort(a, keyIndex + 1, end);
}

//2、递归法优化（小区间优化，减少递归）
void insertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int insert = a[i + 1];
		int end = i;
		while (end >= 0)
		{
			if (a[end] > insert)
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = a[end];
	}
}
void quickSort_plus(int* a, int begin, int end)
{
	if (begin >= end)//当该序列只有一个数或没有数的时候，无需排序，直接返回
	{
		return;
	}
	if (end - begin > 10)//子区间数据较多时继续选择分割子区间的方式
	{
		int keyIndex = partSort(a, begin, end);
		//此时经过上面的交换，key的位置确定，只需要递归将key左边和右边的序列进行排序(类似二叉树的前序遍历)
		quickSort(a, begin, keyIndex - 1);
		quickSort(a, keyIndex + 1, end);
	}
	else//子区间数据量较少（这里是小于等于10），再分割子区间递归就显得不值得了，我们选择插入排序直接处理
	{
		insertSort(a + begin, end - begin + 1);
	}
}

//3、迭代法（类似二叉树的层序遍历）
void quickSort_iterate(int* a, int left, int right)
{
	Stack s;
	StackInit(&s);
	//将区间的左右边界入栈
	StackPush(&s, left);
	StackPush(&s, right);
	while (!StackEmpty(&s))
	{
		//取得当前需要排序的区间左右边界:先取right，再取left
		right = StackTop(&s);
		StackPop(&s);
		left = StackTop(&s);
		StackPop(&s);
		int midIndex = digHole_partSort_plus(a, left, right);
		//区间边界：先入left，再入right
		//midIndex左区间和右区间元素个数大于1的情况才能入栈
		if (left < midIndex - 1)
		{
			StackPush(&s, left);
			StackPush(&s, midIndex - 1);
		}
		if (midIndex + 1 < right)
		{
			StackPush(&s, midIndex + 1);
			StackPush(&s, right);
		}
	}
	StackDestroy(&s);
}
