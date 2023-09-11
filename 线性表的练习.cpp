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
//已知长度为n的线性表A采用顺序存储结构，请设计一个时间复杂度为O(n)、空间复杂度为O(n)的算法
//该算法可删除线性表中所有值为item的数据元素
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