#include<stdlib.h>
#define MAXSIZE 100			//˳�����ܴﵽ����󳤶�
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char ElemType;
typedef struct {
	ElemType* elem;			//�洢�ռ�Ļ���ַ
	int length;				//��ǰ����
}SqList;
//˳���ĳ�ʼ��
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//˳����ȡֵ
Status GetElem_SqList(SqList L, int i,ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//˳���Ĳ���
int LocateElem_SqList(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}
//˳���Ĳ���
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
//˳����ɾ��
Status DeleteSqList(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}