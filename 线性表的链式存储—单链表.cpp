#include <cstddef>
#include <stdio.h>
#include <iostream>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;					//����������
	struct LNode* next;				//����ָ����
}LNode,*LinkList;
//������ĳ�ʼ��
Status InitLinkList(LinkList& L) {
	LNode* L = new LNode;
	L->next = NULL;
	return OK;
}
//�������ȡֵ
Status GetElem_LinkList(LinkList L, int i, ElemType& e) {
	LNode* p = L->next;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (j > i || !p)
		return ERROR;
	e = p->data;
	return OK;
}
//������Ĳ���
LNode* LocateLinkList(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//������Ĳ���
Status InsertLinkList(LinkList& L, int i, ElemType e) {
	LNode* p = L;
	int j = 0;
	while (p && j < (i - 1)) {
		j++;
		p = p->next;
	}
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
//�������ɾ��
Status DeleteLinkList(LinkList& L, int i) {
	LNode* p = L;
	int j = 0;
	while (p->next && j < i - 1) {
		p = p->next;
		j++;
	}
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//ǰ�巨����������
void CreateLinkList_H(LinkList& L,int n) {
	LNode* L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
}
//��巨����������
void CreateLinkList_R(LinkList& L, int n) {
	LNode* L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
}