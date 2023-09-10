#include <cstddef>
#include <stdio.h>
typedef struct PNode {
	float coef;
	int expn;
	struct PNode* next;
}PNode,*Polynomial;
//多项式的创建
void CreatePolyn(Polynomial& P, int n) {
	PNode* P = new PNode;
	P->next = NULL;
	for (int i = 0; i < n; i++) {
		PNode* s = new PNode;
		PNode* q = P->next;
		PNode* pre = P;
		scanf(&s->coef);
		scanf(&s->expn);
		while (q && q->expn < s->expn) {
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}
//多项式的相加
void AddPolyn(Polynomial& Pa, Polynomial& Pb) {
	PNode* p1 = Pa->next;
	PNode* p2 = Pb->next;
	PNode* p3 = Pa;
	while (p1 && p2) {
		if (p1->expn == p2->expn) {
			int sum = p1->coef + p2->coef;
			if (sum != 0) {
				p1->coef = sum;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				PNode* r = p2;
				p2 = p2->next;
				delete r;
			}
			else {
				PNode* r = new PNode;
				r = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p2 = p2->next;
				delete r;
			}
		}
		else if (p1->expn < p2->expn) {
			p3->next = p1;
			p3 = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p3 = p2;
			p2 = p2->next;
		}
	}
	p3->next = p1 ? p1 : p2;
	delete Pb;
}