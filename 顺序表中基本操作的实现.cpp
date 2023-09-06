#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status; 
typedef char ElemType;
typedef struct {
	ElemType* elem;
	int length;
}SqList;
//顺序表的初始化
Status InitList_Sq(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)			//为顺序表分配空间
		exit(OVERFLOW);		//存储分配失败退出
	L.length = 0;			//空表长度为0
	return OK;
}
//销毁顺序表L
void DestroyList(SqList& L) {
	if (L.elem)
		free(L.elem);		//释放存储空间
}
//清空顺序表L
void ClearList(SqList& L) {
	L.length = 0;
}
//求顺序表L的长度
int GetLength(SqList L) {
	return L.length;
}
//判断顺序表L是否为空
int IsEmpty(SqList L) {
	if (L.length == 0)
		return 1;
	else
		return 0;
}
//顺序表的取值(根据位置i获取相应位置数据元素的内容)
int GetElem(SqList L, int i, ElemType& e) {
	if (i < 1 || i > L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//在顺序表L中查找值为e的数据元素，返回其序号
int LocateElem(SqList L, ElemType& e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) 
			return i + 1;
		return 0;
	}
}
//顺序表的插入
Status ListInsert(SqList L, int i, ElemType e) {
	if (1 > i || i > L.length + 1)
		return ERROR;					//i值不合法
	if (L.length == MAXSIZE)			//当前存储空间已满
		return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];		//插入位置及之后的元素后移
	}
	L.elem[i - 1] = e;					//放入新元素
	L.length++;
	return OK;
}
//顺序表的删除
Status ListDelete(SqList& L, int i) {
	if (i < 1 || i > L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1;j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}