#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
int main()
{
	SListNode* list = NULL;
	SListPushBack(&list, 1);
	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(list);
	SListPushFront(&list, 0);
	SListPushFront(&list, -1);
	SListPrint(list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(list);
	SListPopFront(&list);
	SListPopFront(&list);
	SListPrint(list);
	SListNode* p = SListFind(list, 1);
	SListInsertAfter(p, 2);
	SListPrint(list);
	SListEraseAfter(p);
	SListPrint(list);
	SListDestory(&list);
	return 0;
}