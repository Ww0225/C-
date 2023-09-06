#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef struct {

}ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//单链表的初始化
Status InitList_L(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));	//new LNode;
	L->next = NULL;
	return OK;
}
//判断链表是否为空
int ListEmpty(LinkList L) {
	if (L->next)
		return 0;
	else
		return 1;
}
//销毁单链表L
Status DestroyList_L(LinkList& L) {
	LNode *p;
	while (L != NULL) {
		p = L;
		L = L -> next;
		free(p);
	}
	return OK;
}
//清空链表
Status ClearList(LinkList& L) {
	LNode* p, * q;
	p = L->next;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
	return OK;
}