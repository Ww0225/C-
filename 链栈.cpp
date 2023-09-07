#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
//��ջ�ĳ�ʼ��
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}
//��ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S) {
	if (S == NULL)
		return TRUE;
	return FALSE;
}
//��ջ����ջ
Status Push(LinkStack& S, SElemType e) {
	StackNode* p = new StackNode;
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
//��ջ�ĳ�ջ
Status Pop(LinkStack& S, SElemType &e) {
	if (S == NULL)
		return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//ȡջ��Ԫ��
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}