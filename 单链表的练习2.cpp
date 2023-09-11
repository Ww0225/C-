#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode,*LinkList;
//设计一个算法删除递增有序链表中值大于mink且小于maxk的所有元素
//（mink和maxk是给定的两个参数，其值可以和表中的元素相同，也可以不同）
void DeleteMinMax(LinkList& L, int mink, int maxk) {
	LNode* p = L;
	while (p) {
		if (p->data < maxk && p->data > mink) {
			LNode* q = p->next;
			p->next = q->next;
			delete q;
			p = p->next;
		}
		else
			p = p->next;
	}
}