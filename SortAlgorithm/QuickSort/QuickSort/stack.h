#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

//初始化栈
void StackInit(Stack* ps);
//销毁栈
void StackDestroy(Stack* ps);
//入栈
void StackPush(Stack* ps, STDataType x);
//出栈
void StackPop(Stack* ps);
//获取栈顶元素
STDataType StackTop(Stack* ps);
//检测栈是否为空
int StackEmpty(Stack* ps);
