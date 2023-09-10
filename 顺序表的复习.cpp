#include<stdlib.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char ElemType;
typedef struct {
	ElemType* elem;
	int length;
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
Status GetElem_SqList(SqList L,int i, ElemType &e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//˳���Ĳ���
int LocatElem_SqList(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}
//˳���Ĳ���
Status InsertSqList(SqList& L,int i, ElemType e) {
	if (i<1 || i>L.length+1)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length-1;j>i;j--) {
		L.elem[j+1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
//˳����ɾ��
Status SqListDelete(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1;j++) {
		L.elem[j-1] = L.elem[j];
	}
	L.length--;
	return OK;
}
//˳��������
void DestorySqList(SqList& L) {
	if (L.elem)
		free(L.elem);
}
//˳�������
void ClearSqList(SqList& L) {
	L.length = 0;
}
//˳���ĳ���
int GetLength_SqList(SqList& L) {
	return L.length;
}
//�ж�˳����Ƿ�Ϊ��
int IsEmpyty_SqList(SqList& L) {
	if (L.length == 0)
		return 1;
	else
		return 0;
}
//����˳���ĺϲ�
void MergeSqList(SqList La, SqList Lb, SqList& Lc) {
	Lc.length = La.length + Lb.length;
	Lc.elem = new ElemType[Lc.length];
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem;
	ElemType* pc = Lc.elem;
	ElemType* pa_last = La.elem + La.length - 1;
	ElemType* pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
}