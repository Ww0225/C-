#include <cstddef>
#include <iostream>
typedef struct PNode {
	float coef;
	int expn;
	struct PNode* next;
}PNode,*Polynomial;
void CreatePolyn(Polynomial& p, int n) {
	PNode* P = new PNode;
	P->next = NULL;
	for (int i = 1; i <= n; i++) {
		PNode* s = new PNode;
		std::cin >> s->coef >> s->expn;
		PNode* pre = P;
		PNode* q = P->next;
		while (q && q->expn < s->expn) {
			pre = q;
			q = q->next;
		}
		s->next = q;
		pre->next = s;
	}
}
void AddPolyn(Polynomial& pa, Polynomial& pb) {
	PNode* p1 = pa->next;
	PNode* p2 = pb->next;
	PNode* p3 = pa;
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
				PNode* r = p1;
				p3->next = p1;
				p3 = p1;
				p1 = p1->next;
				delete r;
				r = p2;
				p3->next = p2;
				p3 = p2;
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
	delete pb;
}