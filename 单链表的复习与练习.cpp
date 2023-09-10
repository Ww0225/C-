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
//������ĳ�ʼ��
Status InitLinkList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return 0;
}
//�������ȡֵ
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
//������İ�ֵ����
LNode* LocateElem_LinkList(LinkList L, ElemType e) {
	LNode* p = L->next;
	while (p && p->data != e) {
		p = p->next;
	}
	return p;
}
//������Ĳ���
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
//�������ɾ��
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
//ǰ�巨����������
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
//��巨����������
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
//���ٵ�����
Status DestoryLinkList(LinkList& L) {
	LNode* p = new LNode;
	while (L != NULL) {
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}
//��յ�����
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
//������ı�
int LengthLinkList(LinkList L) {
	LNode* p = L->next;
	int i = 0;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
//��βָ��ѭ������ĺϲ�
LinkList ConnectLinkList(LinkList La, LinkList Lb) {
	LNode* p = La->next;
	La->next = Lb->next->next;
	delete Lb->next;
	Lb->next = p;
	return Lb;
}
//�����������ϲ�
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
//��������������������ϲ�Ϊһ����������������Ҫ����������ʹ��ԭ����������Ĵ洢�ռ�
//������ռ�������Ĵ洢�ռ䡣���в��������ظ�������
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
//�������ǵݼ�����������ϲ�Ϊһ���ǵ�������������Ҫ��������
//��ʹ��ԭ����������Ĵ洢�ռ䣬������ռ�������Ĵ洢�ռ䡣������������ظ���Ԫ��
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
//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�
//�����һ���㷨���������A��B�Ľ�����������������A�����С�
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
//��֪��������A��B�ֱ��ʾ�������ϣ���Ԫ�ص������С�������㷨�����������A��B�Ĳ
//��������A�г��ֶ�����B�г��ֵ�Ԫ�������ɵļ��ϣ������������ͬ������ʽ�洢
//ͬʱ���ظü��ϵ�Ԫ�ظ���
int DSLinkList(LinkList& A, LinkList B) {//DS-�
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
//����㷨��һ����ͷ���ĵ�����A�ֽ�Ϊ����������ͬ�ṹ������B��C��
//����B��Ľ��ΪA����ֵС��0�Ľ�㣬��C��Ľ��ΪA����ֵ����0�Ľ��
//������A�е�Ԫ��Ϊ��0������Ҫ��B��C������A��Ľ�㣩
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
//���һ���㷨��ͨ��һ�˱���ȷ������Ϊn�ĵ�������ֵ���Ľ��
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
//���һ���㷨�������������н������ӷ���ԭ�ء���ת����Ҫ�������ԭ��Ĵ洢�ռ�
//���仰˵��Ҫ���㷨�Ŀռ临�Ӷ�ΪO(1)
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