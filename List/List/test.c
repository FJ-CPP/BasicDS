#define _CRT_SECURE_NO_WARNINGS 1
#include "list.h"
int main()
{
	ListNode* list = ListCreate();
	ListPushBack(list, 1);
	ListPushBack(list, 2);
	ListPushBack(list, 3);
	ListPushBack(list, 4);
	ListPrint(list);

	ListPopBack(list);
	ListPopBack(list);
	ListPrint(list);

	ListPushFront(list, 0);
	ListPushFront(list, -1);
	ListPushFront(list, -2);
	ListPrint(list);

	ListPopFront(list);
	ListPopFront(list);
	ListPrint(list);

	ListNode* p1 = ListFind(list, 0);
	if (p1 != NULL)
	{
		ListInsert(p1, 10);
		ListPrint(list);
	}
	
	ListNode* p2 = ListFind(list, 0);
	ListErase(p2);
	ListPrint(list);

	ListNode* p3 = ListFind(list, 1);
	ListErase(p3);
	ListPrint(list);


	ListPrint(list);
	return 0;
}