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
//À≥–Ú’ªµƒ≥ı ºªØ
Status InitStack(SqStack& S) {
	S.base = new SElemType[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//À≥–Ú’ª «∑ÒŒ™ø’
Status StackEmpty(SqStack S) {
	if (S.base == S.top)
		return TRUE;
	else
		return FALSE;
}
//À≥–Ú’ª≥§∂»
int StackLength(SqStack S) {
	return S.top - S.base;
}
//«Âø’À≥–Ú’ª
Status ClearStack(SqStack S) {
	if(S.base)
		S.top = S.base;
	return OK;
}
//œ˙ªŸÀ≥–Ú’ª
Status DestoryStack(SqStack S) {
	if (S.base) {
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}
//À≥–Ú’ªµƒ»Î’ª
Status Push(SqStack& S, SElemType e) {
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++ = e;
	return OK;
}
//À≥–Ú’ªµƒ≥ˆ’ª
Status Pop(SqStack& S, SElemType& e) {
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}