#include <cstddef>
#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef char SElemType;
typedef char ElemType;
typedef int Status;
typedef struct {
	SElemType* base;			//ջ��ָ��
	SElemType* top;				//ջ��ָ��
	int stacksize;				//ջ���õ��������
}SqStack;
typedef struct StackNode{
	SElemType data;
	struct StackNode* next;
}StackNode,*LinkStack;
//˳��ջ�ĳ�ʼ��
Status InitSqStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.base = S.top;
	S.stacksize = MAXSIZE;
	return OK;
}
//˳��ջ����ջ
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
//˳��ջ�ĳ�ջ
Status Pop(SqStack& S, SElemType& e) {
	if (S.top - S.base == 0)
		return ERROR;
	e = *--S.top;
	return OK;
}
//˳��ջȡջ��Ԫ��
SElemType GetTop(SqStack S) {
	if (S.top != S.base)
		return *(S.top - 1);
}
//��ջ�ĳ�ʼ��
Status InitLinkStack(LinkStack& S) {
	S = NULL;
	return OK;
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
Status Pop(LinkStack& S, SElemType e) {
	if (S == NULL)
		return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//��ջ��ȡջ��Ԫ��
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}