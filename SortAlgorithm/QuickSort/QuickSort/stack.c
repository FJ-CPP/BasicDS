#define _CRT_SECURE_NO_WARNINGS 1
#include "stack.h"
//³õÊ¼»¯Õ»
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_top = ps->_capacity = 0;
}
//Ïú»ÙÕ»
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_a = NULL;
}
//ÈëÕ»
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_top == ps->_capacity)//À©ÈÝ
	{
		ps->_capacity = ps->_capacity == 0 ? 4 : 2 * ps->_capacity;
	}
	STDataType* tmp = (STDataType*)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	if (tmp)
	{
		ps->_a = tmp;
		ps->_a[ps->_top] = x;
		++ps->_top;
	}
	else
	{
		perror("realloc failure in realloc");
		exit(-1);
	}
}
//³öÕ»
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}
//»ñÈ¡Õ»¶¥ÔªËØ
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}
//¼ì²âÕ»ÊÇ·ñÎª¿Õ
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->_top == 0;
}