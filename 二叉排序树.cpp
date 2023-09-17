#include <cstddef>
#include <iostream>
#define ENDFLAG 0
typedef KeyType;
typedef InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct BSTNode {
	ElemType data;
	struct BSTNode* lchild, * rchild;
}BSTNode,*BSTree;
BSTree T;
//¶þ²æÅÅÐòÊ÷µÄµÝ¹é²éÕÒ
BSTree SearchBST(BSTree T, KeyType key) {
	if (!T || key == T->data.key)
		return T;
	else if (key < T->data.key)
		return SearchBST(T->lchild, key);
	else
		return SearchBST(T->rchild, key);
}
//¶þ²æÅÅÐòÊ÷µÄ²åÈë
void InsertBST(BSTree& T, ElemType e) {
	if (!T) {
		BSTNode* s = new BSTNode;
		s->data = e;
		s->rchild = s->lchild = NULL;
		T = s;
	}
	else if (e.key < T->data.key) {
		InsertBST(T->lchild, e);
	}
	else
		InsertBST(T->rchild, e);
}
//¶þ²æÅÅÐòÊ÷µÄ´´½¨
void CreateBST(BSTree& T) {
	T = NULL;
	ElemType e;
	scanf(&e);
	while (e.key != ENDFLAG) {
		InsertBST(T, e);
		scanf(&e);
	}
}
//¶þ²æÅÅÐòÊ÷µÄÉ¾³ý
void DeleteBST(BSTree& T,KeyType key) {
	BSTNode* p = T;
	BSTNode* f = NULL;
	while (p) {
		if (key == p->data)
			break;
		f = p;
		if (key < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if (!p)
		return;
	BSTNode* q = p;
	if (p->lchild && p->rchild) {
		BSTNode* s = p->lchild;
		while (s->rchild) {
			q = s;
			s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		delete s;
		return;
	}
	else if (!p->rchild) {
		p = p->lchild;
	}
	else if (!p->lchild) {
		p = p->rchild;
	}
	if (!f)
		T = p;
	else if (q == f->lchild)
		f->lchild = p;
	else
		f->rchild = p;
	delete q;
}