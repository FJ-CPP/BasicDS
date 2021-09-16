#define _CRT_SECURE_NO_WARNINGS 1
#include "heap.h"
int main()
{
	Heap hp;
	int a[] = { 5,13,54,32,16,21,27,36,45,58,62,77,91,88 };
	HeapCreate(&hp, a, sizeof(a) / sizeof(int));
	HeapPrint(&hp);
	printf("\n");

	printf("%d\n",HeapSize(&hp));
	printf("\n");

	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");

	HeapPush(&hp,100);
	HeapPrint(&hp);
	printf("\n");

	HeapPush(&hp, 100);
	HeapPrint(&hp);
	printf("\n");

	HeapPop(&hp);
	HeapPrint(&hp);
	printf("\n");
	return 0;
}