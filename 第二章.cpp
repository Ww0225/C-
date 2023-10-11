#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkList;
typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;
typedef struct {
	ElemType *elem;
	int length;
}SqList;
Status InitSqList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		exit(OVERFLOW);
	L.length = 0;
	return OK;
}
void Destroy(SqList& L) {
	if (L.elem)
		delete L.elem;
}
void ClearSqList(SqList& L) {
	L.length = 0;
}
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
int LocatElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}
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
Status DeleteSqList(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; i <= L.length; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
Status InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return OK;
}
Status DestoryLinkList(LinkList& L) {
	LNode* p = new LNode;
	while (L) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}
Status ClearLinkList(LinkList& L) {
	LNode* p = L->next;
	LNode* q = new LNode;
	while (p) {
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}
int LengthLinkList(LinkList L) {
	int i = 0;
	LNode* p = L->next;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}
Status GetElem_L(LinkList& L, int i,ElemType& e) {
	int j = 1;
	LNode* p = L->next;
	while (p && j < i) {
		j++;
		p = p->next;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
LNode* LocateElem_L(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e)
		p = p->next;
	return p;
}
//int LocateElem_L(LinkList L, ElemType e) {
//	LNode* p = L->next;
//	int j = 0;
//	while (p && p->data != e) {
//		j++;
//		p = p->next;
//	}
//	if (p)
//		return j;
//	else
//		return 0;
//}
Status InsertList_L(LinkList& L, int i, ElemType e) {
	int j = 0;
	LNode* p = L;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* s = new LNode;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}
Status DeleteList_L(LinkList& L, int i) {
	int j = 0;
	LNode* p = L;
	while (p && j < i - 1) {
		j++;
		p = p->next;
	}
	if (!p->next || j > i - 1)
		return ERROR;
	LNode* q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
Status CreateLinkList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	for (int i = 1; i <= n; i++) {
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = L->next;
		L->next = p;
	}
	return OK;
}
Status CreateLinkList_R(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = L;
	for (int i = 1; i <= n; i++) {
		LNode* p = new LNode;
		std::cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	return OK;
}
LinkList Connect(LinkList TA, LinkList TB) {
	LNode* p = TA->next;
	TA->next = TB->next->next;
	delete TB->next;
	TB->next = p;
	return TB;
}
Status Insert_DuL(DuLinkList& L, int i) {
	DuLNode* p = L;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	DuLNode* s = new DuLNode;
	std::cin >> s->data;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return OK;
}
Status Delete_DuL(DuLinkList& L, int i) {
	DuLNode* p = L;
	int j = 0;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}
Status unionList(SqList& LA, SqList LB) {
	ElemType e;
	for (int i = 1; i <= LB.length; i++) {
		GetElem(LB, i, e);
		if (!LocatElem(LA, e))
			InsertSqList(LA, ++LA.length, e);
	}
}
void Merge_SqList(SqList LA, SqList LB, SqList& LC) {
	ElemType* pa = LA.elem;
	ElemType* pb = LB.elem;
	LC.length = LA.length + LB.length;
	LC.elem = new ElemType[LC.length];
	ElemType* pc = LC.elem;
	ElemType* pa_last = LA.elem + LA.length - 1;
	ElemType* pb_last = LB.elem + LB.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
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
void Merge_LinkList(LinkList& LA, LinkList& LB,LinkList& LC) {
	LC = LA;
	LNode* pa = LA->next;
	LNode* pb = LB->next;
	LNode* pc = LC;
	while (pa && pb) {
		if (pa->data < pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data) {
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		else {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			LNode* q = pb->next;
			delete pb;
			pb = q;
		}
	}
	pc->next = pa ? pa : pb;
	delete LB;
}
LNode* MAXNode_L(LinkList L) {
	if (!L || !L->next)
		return 0;
	LNode* maxNode = L;
	LNode* p = L->next;
	int max = L->data;
	while (p) {
		if (max < p->data) {
			max = p->data;
			maxNode = p;
			p = p->next;
		}
	}
	return maxNode;
}
void reverseLinkList(LinkList& L) {
	LNode* p = L->next;
	L->next = NULL;
	while (p) {
		LNode* q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
void unionList_L(LinkList& LA, LinkList& LB,LinkList& LC) {
	LNode* pa = LA->next;
	LNode* pb = LB->next;
	LC = LA;
	LNode* pc = LC;
	while (pa && pb) {
		if (pa->data == pb->data) {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
			LNode* p = pb;
			pb = pb->next;
			delete pb;
		}
		else if (pa->data < pb->data) {
			LNode* p = pa;
			pa = pa->next;
			delete p;
		}
		else {
			LNode* p = pb;
			pb = pb->next;
			delete pb;
		}
	}
	while (pa) {
		LNode* p = pa;
		pa = pa->next;
		delete p;
	}
	while (pb) {
		LNode* p = pb;
		pb = pb->next;
		delete pb;
	}
	pc->next = NULL;
	delete LB;
}
void Difference(LinkList& LA, LinkList& LB, int& n) {
	LNode* pa = LA->next;
	LNode* pb = LB->next;
	LNode* pre = LA;
	while (pa && pb) {
		if (pa->data < pb->data) {
			n++;
			pre = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data) {
			pb = pb->next;
		}
		else {
			pre->next = pa->next;
			LNode* p = pa;
			pa = pa->next;
			delete p;
		}
	}
	while (pa) {
		n++;
		pa = pa->next;
	}
}
void Decompose(LinkList& LA, LinkList& LB, LinkList& LC) {
	LNode* pa = LA->next;
	LNode* LB = NULL;
	LNode* LC = NULL;
	while(pa) {
		LNode* r = pa->next;
		if (pa->data < 0) {
			pa->next = LB->next;
			LB->next = pa;
		}
		else if (pa->data > 0) {
			pa->next = LC->next;
			LC->next = pa;
		}
		pa = r;
	}
}
ElemType MAX(LinkList L) {
	if (!L || !L->next)
		return NULL;
	LNode* pmax = L->next;
	LNode* p = L->next->next;
	while (p) {
		if (p->data > pmax->data)
			pmax = p;
		p = p->next;
	}
	return pmax->data;
}
void DeleteMINMAX(LinkList& L, int mink, int maxk) {
	LNode* p = L->next;
	LNode* pre = new LNode;
	LNode* q = new LNode;
	while (p && p->data <= mink) {
		pre = p;
		p = p->next;
	}
	if (p) {
		while (p && p->data > maxk) {
			p = p->next;
		}
		q = pre->next;
		pre->next = p;
		while (q != p) {
			LNode* s = q->next;
			delete q;
			q = s;
		}
	}
}
void Exchange(DuLinkList p) {
	DuLNode* q = p->prior;
	q->prior->next = p;
	p->prior = q->prior;
	q->next = p->next;
	p->next->prior = p->prior;
	p->next->prior = q;
	p->next = q;
}
void DeleteItem(SqList& L, int item) {
	int k = 0;
	for (int i = 0; i < L.length; i++) {
		L.elem[k] = L.elem[i];
		k++;
	}
	L.length = k;
}