#include<stdio.h>
#include <malloc.h>
#define OK 1
typedef char TElemType;
#define MAXSIZE 100
#define ERROR 0 
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef char SElemType;
typedef struct StackNode {
	SElemType data;
	struct StackNode* next;
}StackNode, * LinkStack;
//��ջ�ĳ�ʼ��
Status InitStack(LinkStack& S) {
	S = NULL;
	return OK;
}
//��ջ�Ƿ�Ϊ��
Status StackEmpty(LinkStack S) {
	if (S == NULL)
		return TRUE;
	return FALSE;
}
//��ջ����ջ
Status Push(LinkStack& S, SElemType e) {
	StackNode* P = new StackNode;
	P->data = e;
	P->next = S;
	S = P;
	return OK;
}
//��ջ�ĳ�ջ
Status Pop(LinkStack& S, SElemType& e) {
	if (S == NULL)
		return ERROR;
	e = S->data;
	StackNode* p = S;
	S = S->next;
	delete p;
	return OK;
}
//ȡջ��Ԫ��
SElemType GetTop(LinkStack S) {
	if (S != NULL)
		return S->data;
}
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
//�������������
Status PreOrderTraverse(BiTree T) {
	if (T == NULL)
		return OK;
	else {
		printf(T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
//�������������
Status InOrderTraverse(BiTree T) {
	if (T == NULL)
		return OK;
	else {
		InOrderTraverse(T->lchild);
		printf(T->data);
		InOrderTraverse(T->rchild);
	}
}
//�������������
Status PostOrderTraverse(BiTree T) {
	if (T == NULL)
		return OK;
	else {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf(T->data);
	}
}
//��������ķǵݹ��㷨
Status InOrderTraverse(BiTree T) {
	LinkStack S = (LinkStack)malloc(sizeof(StackNode));
	InitStack(S);
	BiTNode* q = new BiTNode;
	BiTNode* p = T;
	while (p || !StackEmpty(S)) {
		if (p) {
			Push(S, p);
			p = p->lchild;
		}
		else {
			Pop(S, q);
			printf(q->data);
			p = q->rchild;
		}
	}
	return OK;
}
//���������������������
Status CreateBiTree(BiTree& T) {
	char ch;
	scanf(&ch);
	if (ch == '#')
		T = NULL;
	else {
		BiTNode* T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}
//���ƶ�����
int Copy(BiTree T, BiTree& NewT) {
	if (T == NULL)
		return 0;
	else {
		BiTNode* NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild, NewT->lchild);
		Copy(T->rchild, NewT->rchild);
	}
}
int Depth(BiTree T) {
	int m = 0;
	int n = 0;
	if (T == NULL)
		return 0;
	else {
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}
//�������Ľ�����
int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
//��������Ҷ�ӽ�����
int LeadCount(BiTree T) {
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeadCount(T->lchild) + LeadCount(T->rchild);
}