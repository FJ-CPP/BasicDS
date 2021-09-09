#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
int main()
{
	SeqList psl;
	SeqListInit(&psl);
	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPrint(&psl);
	SeqListPopBack(&psl);
	SeqListPopBack(&psl);
	SeqListPrint(&psl);
	SeqListInsert(&psl, 1, 2);
	SeqListPrint(&psl);
	SeqListPushFront(&psl, 0);
	SeqListPrint(&psl);
	SeqListPopFront(&psl);
	SeqListPrint(&psl);
	SeqListErase(&psl, 1);
	SeqListPrint(&psl);
	SeqListDestory(&psl);
	return 0;
}