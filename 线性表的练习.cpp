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
//��֪����Ϊn�����Ա�A����˳��洢�ṹ�������һ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(n)���㷨
//���㷨��ɾ�����Ա�������ֵΪitem������Ԫ��
void DeleteItem(SqList& L,ElemType item) {
	int j = 0;
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] != item) {
			L.elem[j] = L.elem[i];
			j++;
		}
	}
	L.length = j;
}