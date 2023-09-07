#include <malloc.h>
#define OK 1
#define ERROR 0
typedef char Elemtype;
typedef int Status;
typedef struct LNode{
	Elemtype data;
	struct LNode* next;
}LNode,*LinkList;
//������ĳ�ʼ��
Status InitList_L(LinkList& L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	return OK;
}
//�жϵ������Ƿ�Ϊ��
int IsEmpty(LinkList L) {
	if (L->next == NULL)
		return 1;
	else
		return 0;
}
//���ٵ�����
Status DestoryList(LinkList& L) {
	LNode* p;
	while (L != NULL) {
		p = L;
		L = L->next;
		free(p);
	}
	return OK;
}
//��յ�����
Status ClearList(LinkList& L) {
	LNode* p, * q;
	p = L->next;
	while (p) {
		q = p;
		free(p);
		p = q->next;
	}
	L->next = NULL;
	return OK;
}
//������ı�
int Length_L(LinkList& L) {
	int i = 0;
	LNode* p = L->next;
	while (p) {
		p = p->next;
		i++;
	}
	return i;
}
//�������ȡֵ
Status GetElem_L(LinkList L, int i, Elemtype e) {
	LNode* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	if (i > j || !p)
		return ERROR;
	e = p->data;
	return OK;
}
//����-�����ĺϲ�
void MergeList_L(LinkList& La, LinkList& Lb, LinkList& Lc) {
	LNode* pa = La->next;
	LNode* pb = Lb->next;
	LNode* pc = Lc = La;
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