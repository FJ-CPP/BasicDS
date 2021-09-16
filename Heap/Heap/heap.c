#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"

// 交换两数
void Swap(HPDataType* x, HPDataType* y)
{
	HPDataType tmp = *x;
	*x = *y;
	*y = tmp;
}

// 从上至下调整（建大堆）
void AdjustDown(HPDataType* a, int parent, int n)
{
	assert(a);
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

// 从下至上调整（建大堆）
void AdjustUp(HPDataType* a, int n)
{
	assert(a);
	int child = n - 1;
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	assert(hp);
	/*
	构建堆的过程：
	1、开辟数组
	2、拷贝数组内容
	3、建堆(从最后一个非叶子节点开始调整堆)
	*/
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (hp->_a == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	else
	{
		hp->_capacity = hp->_size = n;
		memcpy(hp->_a, a, n * sizeof(HPDataType));
	}
	for (int i = (hp->_size - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(hp->_a, i, hp->_size);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp)
{
	assert(hp);
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// 堆的打印
void HeapPrint(Heap* hp)
{
	assert(hp);
	int flag = 0;
	int x = 2;
	for (size_t i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_a[i]);
		if (i == flag)
		{
			printf("\n");
			flag += x;
			x *= 2;
		}
	}
	printf("\n");
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_size == hp->_capacity)
	{
		int newcapacity = 2 * hp->_capacity;
		HPDataType* tmp = (HPDataType*)realloc(hp->_a, newcapacity * sizeof(HPDataType));
		if (tmp != NULL)
		{
			hp->_a = tmp;
			hp->_capacity = newcapacity;
		}
		else
		{
			perror("realloc failed");
			exit(-1);
		}
	}
	hp->_a[hp->_size++] = x;
	AdjustUp(hp->_a, hp->_size);
}

// 堆的删除
void HeapPop(Heap* hp)
{
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	--hp->_size;
	AdjustDown(hp->_a, 0, hp->_size);
}

// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	assert(hp);
	assert(!HeapEmpty(hp));
	return hp->_a[0];
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->_size;
}

// 堆的判空
bool HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}
