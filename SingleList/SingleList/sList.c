#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
// 动态申请一个节点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	if (!newnode)
	{
		perror("malloc in BuySListNode");
		return NULL;
	}
	else
	{
		newnode->data = x;
		newnode->next = NULL;
		return newnode;
	}
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	SListNode* cur = *pplist;
	if (cur == NULL)
	{
		*pplist= newnode;
		return;
	}
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = newnode;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* prev = *pplist;
	SListNode* cur = prev->next;
	//只有一个节点
	if (cur == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//有两个及以上结点
	else
	{
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		cur = NULL;
		prev->next = NULL;
	}

}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* newhead = (*pplist)->next;
	free(*pplist);
	*pplist = newhead;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDataType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
// 因为需要遍历链表
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
// 因为需要遍历链表
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
// 单链表的销毁
void SListDestory(SListNode** plist)
{
	assert(plist);
	SListNode* cur = *plist;
	while (cur)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*plist = NULL;
}