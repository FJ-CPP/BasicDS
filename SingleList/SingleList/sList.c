#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
// ��̬����һ���ڵ�
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
// �������ӡ
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
// ������β��
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDataType x)
{
	assert(pplist);
	SListNode* newnode = BuySListNode(x);
	newnode->next = *pplist;
	*pplist = newnode;
}
// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* prev = *pplist;
	SListNode* cur = prev->next;
	//ֻ��һ���ڵ�
	if (cur == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	//�����������Ͻ��
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist && *pplist);
	SListNode* newhead = (*pplist)->next;
	free(*pplist);
	*pplist = newhead;
}
// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
// ��Ϊ��Ҫ��������
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = BuySListNode(x);
	SListNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
// ��Ϊ��Ҫ��������
void SListEraseAfter(SListNode* pos)
{
	assert(pos && pos->next);
	SListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;
}
// �����������
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