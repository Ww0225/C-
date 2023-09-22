#include<stdlib.h>
#include<stdio.h>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int ElemType;
typedef int Status;
typedef struct {
	ElemType *elem;
	int length;
}SqList;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
typedef struct DuLNode{
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;
//˳���ĳ�ʼ��
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//˳����ȡֵ
Status GetElem(SqList L,int i,ElemType e) {
	if (i > L.length||i<1)
		exit(OVERFLOW);
	e = L.elem[i - 1];
	return OK;
}
//˳���Ĳ���
int LocateSqList(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (e == L.elem[i])
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
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
//˳����ɾ��
Status DeleteSqList(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
//������ĳ�ʼ��
Status InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}
//�������ȡֵ
Status GetElem(LinkList L, int i,ElemType& e) {
	LNode* p = L->next;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
//������Ĳ���
int LocateLinkList(LinkList L, ElemType e) {
	int j = 0;
	LNode* p = L->next;
	while (p&&e!=p->data) {
		p = p->next;
		j++;
	}
	return j;
}
LNode* LocateLinkList(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//������Ĳ���
Status InsertLinkList(LinkList& L,int i, ElemType e) {
	LNode* p = L;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status DeleteLinkList(LinkList& L, int i) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//������ǰ�巨
void Create_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;
		scanf(&p->data);
		p->next = L->next;
		L->next = p;
	}
}
//�������巨
void Create_H(LinkList& L, int n) {
	L = new LNode;
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
//˫������Ĳ���
DuLNode* GetElem_DuL(DuLinkList L, int i) {
	int j = 0;
	DuLNode* p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//˫������Ĳ���
Status Insert_DuL(DuLinkList& L, int i, ElemType e) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElem_DuL(L, i)))
		return ERROR;
	DuLNode* s = new DuLNode;
	s->data = e;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
//˫�������ɾ��
Status Delete_DuL(DuLinkList& L, int i) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElem_DuL(L, i)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}
//˳�������ĺϲ�
void MergeSqList(SqList LA, SqList LB, SqList& LC) {
	LC.length = LA.length + LB.length;
	LC.elem = new ElemType[LC.length];
	ElemType* pa = LA.elem;
	ElemType* pb = LB.elem;
	ElemType* pc = LC.elem;
	ElemType* pa_last = LA.elem + LA.length - 1;
	ElemType* pb_last = LB.elem + LB.length - 1;
	while (pa <= pa_last && pb < pb_last) {
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
//��ʽ�����ĺϲ�
void MergeLinkList(LinkList& LA, LinkList& LB, LinkList& LC) {
	LNode* pa = LA->next;
	LNode* pb = LB->next;
	LC = LA;
	LNode* pc = LC;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}	
	}
	pc->next = pa ? pa : pb;
	delete LB;
}