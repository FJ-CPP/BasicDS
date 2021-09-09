#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
void CheckCapacity(SeqList* ps)
{
	assert(ps);
	size_t newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
	SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));
	//If memblock is NULL, realloc behaves the same way as malloc
	if (tmp == NULL)
	{
		perror("realloc in CheckCapacity");
		return;
	}
	else
	{
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
}
// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->capacity = ps->size = 0;
	ps->a = NULL;
}
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListInsert(ps, ps->size, x);
}
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
}
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, 0);
}
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDataType x)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return - 1;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDataType x)
{
	assert(ps && pos >= 0);
	CheckCapacity(ps);
	int i = 0;
	for (i = ps->size; i > pos; i--)
	{
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos >= 0);
	int i = 0;
	for (i = pos; i < ps->size; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}



