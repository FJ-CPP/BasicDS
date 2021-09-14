#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include <stdbool.h>
typedef struct
{
    Stack s1;
    Stack s2;
    size_t sz;//��¼ջ�����ݵĸ���
} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate()
{
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    StackInit(&q->s1);
    StackInit(&q->s1);
    q->sz = 0;
    return q;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x)
{
    //��ջ������ɶ��е�β����ô��Ӿ���ѹջ
    //���ҵ��ǿյ��Ǹ�ջ(������ݵ�ջ)
    Stack* nonemptyS = !StackEmpty(&obj->s1) ? &obj->s1 : &obj->s2;
    StackPush(nonemptyS, x);//ѹջ
    obj->sz++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    //�ҵ���ջ�ͷǿ�ջ
    Stack* emptyS = &obj->s1;
    Stack* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    int sz = obj->sz;
    //��nonemptyS��ǰsz-1����ջ��ѹջ��emptyS
    while (sz > 1)
    {
        int x = StackTop(nonemptyS);
        StackPop(nonemptyS);//��ջ
        sz--;
        StackPush(emptyS, x);//ѹջ
    }
    //��ʱnonemptyS��ʣһ��Ԫ��
    int front = StackTop(nonemptyS);//ȡ��ջ������
    StackPop(nonemptyS);//��ջ��Ԫ�س�ջ���൱�ڳ�����
    //�ٽ�emptyS�еĻָ���nonempty��
    while (!StackEmpty(emptyS))
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    obj->sz--;
    return front;//���ء����С���ͷ
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    //�ҵ���ջ�ͷǿ�ջ
    Stack* emptyS = &obj->s1;
    Stack* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    int sz = obj->sz;
    //��nonemptyS��ǰsz-1����ջ��ѹջ��emptyS
    while (sz > 1)
    {
        int x = StackTop(nonemptyS);
        StackPop(nonemptyS);//��ջ
        sz--;
        StackPush(emptyS, x);//ѹջ
    }
    //��ʱnonemptyS��ʣһ��Ԫ��
    int front = StackTop(nonemptyS);//ȡ��ջ������
    //�ٽ�emptyS�еĻָ���nonempty��
    while (!StackEmpty(emptyS))
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    return front;//���ء����С���ͷ
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj)
{
    StackDestroy(&obj->s1);
    StackDestroy(&obj->s2);
    free(obj);
}
int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
    StackPush(&s, 5);
    StackPush(&s, 6);
	while (!StackEmpty(&s))
	{
		STDataType x = StackTop(&s);
		printf("%d ", x);
		StackPop(&s);
	}
	return 0;
}