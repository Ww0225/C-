#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode, * DuLinkList;
//已知p指向双向循环链表中的一个结点，其结点结构为data、prior、next这3个域
//设计算法change(p)，交换p所指向的结点及其前驱结点的顺序
void change(DuLinkList p) {
	DuLNode* q = p->prior;
	q->next->prior = p;
	p->prior = q->prior;
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;
}