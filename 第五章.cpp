#include <iostream>
#define MAXTSIZE 100
#define MAX_TREE_SIZE 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef int TElemType;
typedef TElemType SqBiTree[MAXTSIZE];
typedef struct BiTNode {
	TElemType data;
	struct BiTNode* lchild, * rchild;
}BiTNode,*BiTree;
typedef struct TriTNode {
	TElemType data;
	struct TriTNode* lchild, * parent, * rchild;
}TriTNode,*TriTree;
typedef struct BiThrNode {
	int data;
	int ltag, rtag;
	struct BiThrNode* lchild, * rchild;
}BiThrNode,*BiThrTree;
typedef struct PTNode {
	TElemType data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;			//根结点的位置和结点个数
}PTree;
typedef struct CTNode {
	int child;
	struct CTNode* next;
}*ChildPtr;
typedef struct {
	TElemType data;
	ChildPtr firstchild;
}CTBox;
typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int n, r;
}CTree;
typedef struct CSNode {
	TElemType data;
	struct CSNode* firstchild, * nextsibling;
}CSNode,*CSTree;
typedef struct {
	BiTNode data[MAXTSIZE];
	int front, rear;
}SqQueue;
typedef struct {
	int weight;
	int parent, lch, rch;
}HTNode,*HuffmanTree;
typedef char** HuffmanCode;
void InOrderTraverse(BiTree T) {
	if (T) {
		InOrderTraverse(T->lchild);
		std::cout << T->data;
		InOrderTraverse(T->rchild);
	}
}
Status InOrderTraverse(BiTree T) {
	InitStack(S);
	BiTNode* p = T;
	BiTNode* q = new BiTNode;
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
void PreOrderTraverse(BiTree T) {
	if (T) {
		std::cout << T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
void PostOrderTraverse(BiTree T) {
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		std::cout << T->data;
	}
}
void LevelOrder(BiTNode* b) {
	SqQueue* qu;
	BiTNode* p = new BiTNode;
	InitQueue(qu);
	EnQueue(qu, b);
	while (!QueueEmpty(qu)) {
		DeQueue(qu, p);
		printf(p->data);
		if (p->lchild != NULL)
			EnQueue(qu, p->lchild);
		if (p->rchild != NULL)
			EnQueue(qu, p->rchild);
	}
}
void CreateBiTree(BiTree& T) {
	char ch;
	scanf(&ch);
	if (ch == '#')
		T = NULL;
	else {
		T = new BiTNode;
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}
void Copy(BiTree T, BiTree& NewT) {
	if (T == NULL) {
		NewT = NULL;
		return;
	}
	else {
		NewT = new BiTNode;
		NewT->data = T->data;
		Copy(T->lchild,NewT->lchild);
		Copy(T->rchild,NewT->rchild);
	}
}
int Depth(BiTree T) {
	if (T==NULL)
		return 0;
	else {
		int m = 0;
		int n = 0;
		m = Depth(T->lchild);
		n = Depth(T->rchild);
		if (m > n)
			return m + 1;
		else
			return n + 1;
	}
}
int NodeCount(BiTree T) {
	if (T == NULL)
		return 0;
	else
		return NodeCount(T->lchild) + NodeCount(T->rchild) + 1;
}
int LeadCount(BiTree T) {
	if (T == NULL)
		return 0;
	if (T->lchild == NULL && T->rchild == NULL)
		return 1;
	else
		return LeadCount(T->lchild) + LeadCount(T->rchild);
}
void CreteHuffmanTree(HuffmanTree& HT, int n) {
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		HT[i].parent = 0;
		HT[i].lch = 0;
		HT[i].rch = 0;
	}
	for (int i = 1; i <= n; i++)
		std::cin >> HT[i].weight;
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void CreatHuffmanCode(HuffmanTree HT,HuffmanCode&HC,int n){
	HC = new char* [n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lch == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}