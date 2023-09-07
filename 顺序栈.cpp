#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0 
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;
typedef struct {
	SElemType* base;
	SElemType* top;
	int stacksize;
}SqStack;
//˳��ջ�ĳ�ʼ��
Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//˳��ջ�Ƿ�Ϊ��
Status StackEmpty(SqStack S) {
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
//˳��ջ����
int StackLength(SqStack S) {
	return S.top - S.base;
}
//���˳��ջ
Status ClearStack(SqStack S) {
	if(S.base)
		S.top = S.base;
	return OK;
}
//����˳��ջ
Status DestoryStack(SqStack S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
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
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}