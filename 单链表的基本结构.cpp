#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef char ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
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
	LNode* p;
	while (L != NULL) {
		p = L;
		L = L->next;
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
//������L�ı�
int ListLength_L(LinkList L) {
	LNode* p;
	p = L->next;
	int i = 0;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
//�������ȡֵ
Status GetElem_L(LinkList& L, int i, ElemType e) {
	LNode* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		i++;
	}
	if (!p || i > j)
		return ERROR;
	e = p->data;
	return OK;
}
//������İ�ֵ����--���ظ�ֵ���ڵĵ�ַ
LNode* LocateElem_L(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//������İ�ֵ����--���ظ�ֵ���ڵ�λ�����
//int LocateElem_L(LinkList L, ElemType e) {
//	LNode* p = L->next;
//	int j = 1;
//	while (p && p->data != e) {
//		p = p->next;
//		j++;
//	}
//	if (p)
//		return j;
//	else
//		return 0;
//}
//�ڵ�����L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status ListInsert(LinkList& L, int i, ElemType e) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		j++;
		p = p->next;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//ɾ��������ĵ�i�����
Status ListDelete(LinkList& L, int i) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		j++;
		p = p->next;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	free(q);		
	return OK;
}
//ǰ�巨����������
void CreateList_H(LinkList& L, int n) {
	LNode* L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		scanf(&p->data);
		p->next = L->next;
		L->next = p;
	}
}
//��巨����������
void CreateList_R(LinkList& L, int n) {
	LNode* L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		scanf(&p->data);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
//��βָ��ѭ������ĺϲ�
LinkList Connect(LinkList Ta, LinkList Tb) {
	LNode* p = new LNode;
	p = Ta->next;
	Ta->next = Tb->next->next;
	delete Tb->next;
	Tb->next = p;
	return Tb;
}