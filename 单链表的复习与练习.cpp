#include <cstddef>
#include<stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int ElemType;
typedef int Status;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//单链表的初始化
Status InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 0;
}
//单链表的取值
Status GetElem_LinkList(LinkList L, int i, ElemType& e) {
	int j = 1;
	LNode* p = L->next;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	e = p->data;
	return OK;
}
//单链表的按值查找
LNode* LocateElem_LinkList(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//单链表的插入
Status InsertLinkList(LinkList& L,int i,ElemType e) {
	LNode* p = L;
	int j = 0;
	while (p && j < (i - 1)) {
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
//单链表的删除
Status Delete_LinkList(LinkList& L,int i) {
	LNode* p = L;
	int j = 0;
	while (p && j < i - 1) {
		p = p->next;
		j++;
	}
	if (!p || j > i - 1)
		return ERROR;
	LNode* q = new LNode;
	q = p->next;
	p->next = q->next;
	delete q;
	return OK;
}
//前插法创建单链表
void CreateLinkList_H(LinkList& L, int n) {
	LNode* L = new LNode;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		char ch;
		LNode* p = new LNode;
		p->data = scanf(&ch);
		p->next = L->next;
		L->next = p;
	}
}
//后插法创建单链表
void CreateLinkList_R(LinkList& L, int n) {
	LNode* L = new LNode;
	LNode* r = L;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		char ch;
		LNode* p = new LNode;
		p->data = scanf(&ch);
		p->next = NULL;
		r->next = p;
		r = p;
	}
}
//销毁单链表
Status DestoryLinkList(LinkList& L) {
	LNode* p = new LNode;
	while (L != NULL) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}
//清空单链表
Status ClearLinkList(LinkList& L) {
	LNode* p, * q = new LNode;
	p = L->next;
	while (L->next != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	return OK;
}
//单链表的表长
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i = 0;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
//带尾指针循环链表的合并
LinkList ConnectLinkList(LinkList La, LinkList Lb) {
	LNode* p = La->next;
	La->next = Lb->next->next;
	delete Lb->next;
	Lb->next = p;
	return Lb;
}
//单链表的有序合并
void MergeLinkList(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	Lc = La;
	LNode* pc = Lc;
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
	delete Lb;
}
//将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间
//不另外占用其他的存储空间。表中不允许有重复的数据
LinkList MergeLinkList_UP(LinkList& La, LinkList& Lb) {
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	LNode* NewL = La;
	while (pa && pb) {
		if (pa->data < pb->data) {
			NewL->next = pa;
			NewL = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data) {
			NewL->next = pb;
			NewL = pb;
			pb = pb->next;
		}
	}
	NewL->next = pa ? pa : pb;
	return NewL;
}
//将两个非递减的有序链表合并为一个非递增的有序链表。要求结果链表
//仍使用原来两个链表的存储空间，不另外占用其他的存储空间。表中允许出现重复的元素
LinkList MergeLinkList_DOWN(LinkList& La, LinkList& Lb) {
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	LNode* NewL = La;
	while (pa && pb) {
		if (pa->data <= pb->data) {
			NewL->next = pb;
			NewL = pb;
			pb = pb->next;
		}
		else {
			NewL->next = pa;
			NewL = pa;
			pa = pa->next;
		}
	}
	NewL->next = pa ? pa : pb;
	return NewL;
}
//已知两个链表A和B分别表示两个集合，其元素递增排列。
//请设计一个算法，用于求出A与B的交集，并将结果存放在A链表中。
void GetUnite(LinkList& A, LinkList B) {
	LNode* pa = A->next;
	LNode* pb = B->next;
	LNode* NewP = new LNode;
	while (pa && pb) {
		if (pa->data == pb->data) {
			NewP->next = pa;
			NewP = pa;
			pa = pa->next;
			pb = pb->next;
		}
		else if (pa->data < pb->data) {
			pa = pa->next;
		}
		else
			pb = pb->next;
	}
	while (A->next) {
		LNode* p = A->next;
		A = A->next;
		delete p;
	}
	A->next = NewP;
}
//已知两个链表A和B分别表示两个集合，其元素递增排列。请设计算法求出两个集合A和B的差集
//（仅由在A中出现而不在B中出现的元素所构成的集合），并将结果以同样的形式存储
//同时返回该集合的元素个数
int DSLinkList(LinkList& A, LinkList B) {//DS-差集
	int count = 0;
	LNode* pa = A->next;
	LNode* pb = B->next;
	LinkList C = (LinkList)malloc(sizeof(LNode));
	while (pa && pb) {
		if (pa->data < pb->data) {
			C->next = pa;
			C = pa;
			pa = pa->next;
			count++;
		}
		else if (pa->data == pb->data) {
			pa = pa->next;
			pb = pb->next;
		}
		else {
			pb = pb->next;
		}
	}
	while (pa) {
		C->next = pa;
		C = pa;
		pa = pa->next;
		count++;
	}
	C->next = NULL;
	return count;
}
//设计算法将一个带头结点的单链表A分解为两个具有相同结构的链表B和C，
//其中B表的结点为A表中值小于0的结点，而C表的结点为A表中值大于0的结点
//（链表A中的元素为非0整数，要求B、C表利用A表的结点）
void DevideLinkList(LinkList& A, LinkList& B, LinkList& C) {
	LNode* pa = A->next;
	LNode* pb = B->next;
	LNode* pc = C->next;
	while (pa) {
		if (pa->data < 0) {
			pb->next = pa;
			pb = pa;
			pa = pa->next;
		}
		else {
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
	}
}
//设计一个算法，通过一趟遍历确定长度为n的单链表中值最大的结点
LNode* MaxLinkList(LinkList L) {
	if (L == NULL||L->next == NULL)
		return 0;
	LNode* MaxNode = L;
	LNode* p = L->next;
	int max = MaxNode->data;
	while (p) {
		if (max < p->data) {
			max = p->data;
			MaxNode = p;
			p = p->next;
		}
	}
	return MaxNode;
}
//设计一个算法，将链表中所有结点的链接方向“原地”逆转，即要求仅利用原表的存储空间
//换句话说，要求算法的空间复杂度为O(1)
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