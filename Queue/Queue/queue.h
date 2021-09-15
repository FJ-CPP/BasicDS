#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QDataType;
typedef struct QNode
{
	QDataType _data;
	struct QNode* _next;
}QNode;
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);
QDataType QueueFront(Queue* pq);
QDataType QueueRear(Queue* pq);
int QueueSize(Queue* pq);
int QueueEmpty(Queue* pq);