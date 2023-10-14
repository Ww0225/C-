#include<stdlib.h>
#define MAXSIZE 100
#define MAXQSIZE 100
#define OK 1
#define OVERFLOW -1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef int QElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
typedef struct {
	QElemType* base;
	int rear;
	int front;
}SqQueue;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
Status InitSqStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.base = S.top;
	S.stacksize = MAXSIZE;
	return OK;
}
Status StackEmpty(SqStack S) {
	if (S.top == S.base)
		return TRUE;
	else
		return FALSE;
}
Status StackLength(SqStack S) {
	return S.top-S.base;
}
Status ClearStack(SqStack& S) {
	if(S.base)
		S.top = S.base;
	return OK;
}
Status DestoryStack(SqStack& S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}
Status Push(SqStack& S,SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
Status Pop(SqStack& S,SElemType& e) {
	if (S.base == S.top)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}
Status StackEmpty_L(LinkStack S) {
	if (S == NULL)
		return TRUE;
	else
		return FALSE;
}
Status Push(LinkStack& S, SElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack& S, SElemType& e) {
	if (S == NULL)
		return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
SElemType GetTop(LinkStack S, SElemType& e) {
	if (S != NULL)
		return S->data;
}
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
}
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
Status EnQueue(SqQueue& Q,QElemType e) {
	if ((Q.rear+1)%MAXQSIZE==Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
QElemType GetTop(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	if (!Q.front)
		exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
Status DestoryQueue(LinkQueue& Q) {
	while (Q.front) {
		QNode* p = Q.front->next;
		delete Q.front;
		Q.front = p;
	}
	return OK;
}
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p = new QNode;
	if (!p)
		exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
Status DeQueue(LinkQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front = p->next;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
Status GetHead(LinkQueue Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.front->next->data;
	return OK;
}