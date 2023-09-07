#define OK 1
#define ERROR 0
typedef char Elemtype;
typedef int Status;
typedef struct DuLNode {
	Elemtype data;
	struct DuLNode* prior, * next;
}DuLNode,*DuLinkList;
//˫������Ĳ���
DuLNode* GetElemP_Dul(DuLinkList L,Elemtype e) {
	DuLNode* p = L->next;
	if (p->data != e)
		p = p->next;
	return p;
}
//˫������Ĳ���
Status ListInsert_DuL(DuLinkList& L, int i, Elemtype e) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElemP_Dul(L, e)))
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
Status ListDelete_DuL(DuLinkList& L, int i,Elemtype e) {
	DuLNode* p = new DuLNode;
	if (!(p = GetElemP_Dul(L,e))) {
		return ERROR;
	}
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return OK;
}
