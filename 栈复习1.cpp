#include <cstddef>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define OVERFLOW -1
#define ERROR 0
typedef int Status;
typedef SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
typedef struct StackNode{
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
//顺序栈的初始化
Status InitSqStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.base = S.top = NULL;
	S.stacksize = MAXSIZE;
	return OK;
}
//顺序栈的入栈
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
//顺序栈的出栈
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
//取栈顶元素
SElemType GetTop(SqStack S) {
	if (S.top != S.base)
		return *(S.top - 1);
}
//链栈的初始化
Status InitLinkStack(LinkStack& S) {
	S = NULL;
	return OK;
}
//链栈的入栈
Status Push(LinkStack& S, SElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//链栈的出栈
Status Pop(LinkStack& S, SElemType& e) {
	if (S == NULL)
		return ERROR;
	e = S->data;
	StackNode* p = S;
	S = p->next;
	delete p;
	return OK;
}
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}