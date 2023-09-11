#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode, * DuLinkList;
//��֪pָ��˫��ѭ�������е�һ����㣬����ṹΪdata��prior��next��3����
//����㷨change(p)������p��ָ��Ľ�㼰��ǰ������˳��
void change(DuLinkList p) {
	DuLNode* q = p->prior;
	q->next->prior = p;
	p->prior = q->prior;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
}