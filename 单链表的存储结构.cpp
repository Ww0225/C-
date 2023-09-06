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
//������ĳ�ʼ��
Status InitList_L(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));	//new LNode;
	L->next = NULL;
	return OK;
}
//�ж������Ƿ�Ϊ��
int ListEmpty(LinkList L) {
	if (L->next)
		return 0;
	else
		return 1;
}
//���ٵ�����L
Status DestroyList_L(LinkList& L) {
	LNode *p;
	while (L != NULL) {
		p = L;
		L = L -> next;
		free(p);
	}
	return OK;
}
//�������
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