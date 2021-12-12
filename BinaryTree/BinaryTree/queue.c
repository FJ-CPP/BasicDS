#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->_front;
	while (cur)
	{
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode)
	{
		newnode->_data = x;
		newnode->_next = NULL;
		if (pq->_front == NULL)//队列为空的情况
		{
			pq->_front = pq->_rear = newnode;
		}
		else
		{
			pq->_rear->_next = newnode;
			pq->_rear = newnode;
		}
	}
	else
	{
		perror("malloc failure in QueuePush");
		exit(-1);
	}
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	if (pq->_front->_next == NULL)//队列只有一个结点的情况
	{
		free(pq->_front);
		pq->_front = pq->_rear = NULL;
	}
	else
	{
		QNode* next = pq->_front->_next;
		free(pq->_front);
		pq->_front = next;
	}
}
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->_front->_data;
}
QDataType QueueRear(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->_rear->_data;
}
int QueueSize(Queue* pq) 
{
	assert(pq);
	int sz = 0;
	QNode* cur = pq->_front;
	while (cur)
	{
		sz++;
		cur = cur->_next;
	}
	return sz;
}
int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}