#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status; 
typedef char ElemType;
typedef struct {
	ElemType* elem;
	int length;
}SqList;
//˳���ĳ�ʼ��
Status InitList_Sq(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)			//Ϊ˳������ռ�
		exit(OVERFLOW);		//�洢����ʧ���˳�
	L.length = 0;			//�ձ���Ϊ0
	return OK;
}
//����˳���L
void DestroyList(SqList& L) {
	if (L.elem)
		free(L.elem);		//�ͷŴ洢�ռ�
}
//���˳���L
void ClearList(SqList& L) {
	L.length = 0;
}
//��˳���L�ĳ���
int GetLength(SqList L) {
	return L.length;
}
//�ж�˳���L�Ƿ�Ϊ��
int IsEmpty(SqList L) {
	if (L.length == 0)
		return 1;
	else
		return 0;
}
//˳����ȡֵ(����λ��i��ȡ��Ӧλ������Ԫ�ص�����)
int GetElem(SqList L, int i, ElemType& e) {
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//��˳���L�в���ֵΪe������Ԫ�أ����������
int LocateElem(SqList L, ElemType& e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) 
			return i + 1;
		return 0;
	}
}
//˳���Ĳ���
Status ListInsert(SqList L, int i, ElemType e) {
	if (1 > i || i > L.length + 1)
		return ERROR;					//iֵ���Ϸ�
	if (L.length == MAXSIZE)			//��ǰ�洢�ռ�����
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];		//����λ�ü�֮���Ԫ�غ���
	}
	L.elem[i - 1] = e;					//������Ԫ��
	L.length++;
	return OK;
}
//˳����ɾ��
Status ListDelete(SqList& L, int i) {
	if (i < 1 || i > L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1;j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}