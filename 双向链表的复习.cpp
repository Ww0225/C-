#define OK 1
#define ERROR 0
typedef int Status;
typedef char ElemType;
typedef struct DuLNode {
	ElemType data;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;
//˫������Ĳ���
DuLNode* GetElem_DuLinkList(DuLinkList L, int i) {
	DuLNode* p = L->next;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	return p;
}
//˫������Ĳ���
Status InsertDuLinkList(DuLinkList& L, int i, ElemType e) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElem_DuLinkList(L, i)))
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
Status DeleteDuLinkList(DuLinkList& L, int i) {
	DuLNode* p = new DuLNode;
	if(!(p = GetElem_DuLinkList(L,i)))
		return ERROR;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}