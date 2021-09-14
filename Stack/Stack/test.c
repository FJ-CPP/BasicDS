#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
#include <stdbool.h>
typedef struct
{
    Stack s1;
    Stack s2;
    size_t sz;//记录栈中数据的个数
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
    //把栈顶想象成队列的尾，那么入队就是压栈
    //先找到非空的那个栈(存放数据的栈)
    Stack* nonemptyS = !StackEmpty(&obj->s1) ? &obj->s1 : &obj->s2;
    StackPush(nonemptyS, x);//压栈
    obj->sz++;
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj)
{
    //找到空栈和非空栈
    Stack* emptyS = &obj->s1;
    Stack* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    int sz = obj->sz;
    //将nonemptyS的前sz-1个出栈并压栈到emptyS
    while (sz > 1)
    {
        int x = StackTop(nonemptyS);
        StackPop(nonemptyS);//出栈
        sz--;
        StackPush(emptyS, x);//压栈
    }
    //此时nonemptyS仅剩一个元素
    int front = StackTop(nonemptyS);//取出栈底数据
    StackPop(nonemptyS);//将栈底元素出栈，相当于出队列
    //再将emptyS中的恢复到nonempty中
    while (!StackEmpty(emptyS))
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    obj->sz--;
    return front;//返回“队列”的头
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj)
{
    //找到空栈和非空栈
    Stack* emptyS = &obj->s1;
    Stack* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    int sz = obj->sz;
    //将nonemptyS的前sz-1个出栈并压栈到emptyS
    while (sz > 1)
    {
        int x = StackTop(nonemptyS);
        StackPop(nonemptyS);//出栈
        sz--;
        StackPush(emptyS, x);//压栈
    }
    //此时nonemptyS仅剩一个元素
    int front = StackTop(nonemptyS);//取出栈底数据
    //再将emptyS中的恢复到nonempty中
    while (!StackEmpty(emptyS))
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    return front;//返回“队列”的头
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