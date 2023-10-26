#include <cstddef>
#include <iostream>
typedef char KeyType;
typedef struct {
	KeyType key;
}ElemType;
typedef struct {
	ElemType* R;
	int length;
}SSTable;
//int Search_Seq(SSTable ST, KeyType key) {
//	for (int i = ST.length; i >= 1; i--)
//		if (ST.R[i].key == key)
//			return i;
//	return 0;
//}
//¸Ä½ø
int Search_Seq(SSTable ST, KeyType key) {
	int i = 0;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; i--);
	return i;
}
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1;
	int high = ST.length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (ST.R[mid].key == key)
			return mid;
		else if (ST.R[mid].key > key)
			high = mid - 1;
		else 
			low = mid + 1;
	}
	return 0;
}
#define ENDFLAG "#"
typedef InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}ElemType;
typedef struct BSTNode {
	ElemType data;
	struct BSTNode* lchid, * rchild;
}BSTNode,*BSTree;
BSTree SearchBST(BSTree T, KeyType key) {
	if ((!T) || T->data.key == key)
		return T;
	else if (T->data.key < key)
		return SearchBST(T->lchid, key);
	else
		return SearchBST(T->rchild, key);
}
void InsertBST(BSTree& T, ElemType e) {
	if (!T) {
		BSTNode* S = new BSTNode;
		S->data = e;
		S->lchid = S->rchild = NULL;
		T = S;
	}
	else if (e.key < T->data.key)
		InsertBST(T->lchid, e);
	else
		InsertBST(T->rchild, e);
}
void CreateBST(BSTree& T) {
	T = NULL;
	ElemType e;
	std::cin >> e;
	while (e != ENDFLAG) {
		InsertBST(T, e);
		std::cin >> e;
	}
}