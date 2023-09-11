#define OK 1
#define ERROR 0
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	LNode* next;
}LNode,*LinkList;
//���һ���㷨ɾ����������������ֵ����mink��С��maxk������Ԫ��
//��mink��maxk�Ǹ�����������������ֵ���Ժͱ��е�Ԫ����ͬ��Ҳ���Բ�ͬ��
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