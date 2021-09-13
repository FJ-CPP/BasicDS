#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
// 创建返回链表的头结点.
ListNode* BuyListNode(LTDataType x)
{
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	if (tmp == NULL)
	{
		perror("malloc failure int BuyListNode");
		exit(-1);
	}
	else
	{
		tmp->_data = x;
		tmp->_next = NULL;
		tmp->_prev = NULL;
		return tmp;
	}
}
ListNode* ListCreate()
{
	ListNode* phead = BuyListNode(-1);
	phead->_next = phead;
	phead->_prev = phead;
	return phead;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead, x);
	/*ListNode* tail = pHead->_prev;
	ListNode* newnode = BuyListNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = pHead;
	pHead->_prev = newnode;*/
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!ListEmpty(pHead));
	ListErase(pHead->_prev);
	/*ListNode* tail = pHead->_prev;
	ListNode* newtail = tail->_prev;
	pHead->_prev = newtail;
	newtail->_next = pHead;
	free(tail);*/
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListInsert(pHead->_next, x);
	/*ListNode* newnode = BuyListNode(x);
	ListNode* next = pHead->_next;
	pHead->_next = newnode;
	newnode->_prev = pHead;
	newnode->_next = next;
	next->_prev = newnode;*/
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!ListEmpty(pHead));
	ListErase(pHead->_next);
	/*ListNode* oldHead = pHead->_next;
	ListNode* newHead = oldHead->_next;
	pHead->_next = newHead;
	newHead->_prev = pHead;
	free(oldHead);*/
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	ListNode* ret = pHead->_next;
	while (ret != pHead)
	{
		if (ret->_data == x)
		{
			return ret;
		}
		ret = ret->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	prev->_next = next;
	next->_prev = prev;
}
bool ListEmpty(ListNode* pHead)
{
	assert(pHead);
	return pHead->_next == pHead;
}