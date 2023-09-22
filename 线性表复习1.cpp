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
//顺序表的初始化
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
//顺序表的取值
Status GetElem(SqList L,int i,ElemType e) {
	if (i > L.length||i<1)
		exit(OVERFLOW);
	e = L.elem[i - 1];
	return OK;
}
//顺序表的查找
int LocateSqList(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (e == L.elem[i])
			return i + 1;
	}
	return 0;
}
//顺序表的插入
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
//顺序表的删除
Status DeleteSqList(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
//单链表的初始化
Status InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}
//单链表的取值
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
//单链表的查找
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
//单链表的插入
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
//单链表前插法
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
//单链表后插法
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
//双向链表的查找
DuLNode* GetElem_DuL(DuLinkList L, int i) {
	int j = 0;
	DuLNode* p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//双向链表的插入
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
//双向链表的删除
Status Delete_DuL(DuLinkList& L, int i) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElem_DuL(L, i)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}
//顺序有序表的合并
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
//链式有序表的合并
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