#include<stdlib.h>
#define MAXSIZE 100			//顺序表可能达到的最大长度
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char ElemType;
typedef struct {
	ElemType* elem;			//存储空间的基地址
	int length;				//当前长度
}SqList;
//顺序表的初始化
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//顺序表的取值
Status GetElem_SqList(SqList L, int i,ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//顺序表的查找
int LocateElem_SqList(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}
//顺序表的插入
Status InsertSqList(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length + 1)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i] = e;
	L.length++;
	return OK;
}
//顺序表的删除
Status DeleteSqList(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}