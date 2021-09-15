#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
int main()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	Queue q2 = q;
	printf("%d\n", QueueSize(&q));
	while (!QueueEmpty(&q2))
	{
		printf("%d ", QueueFront(&q2));
		QueuePop(&q2);
	}
	printf("\n");
	return 0;
}