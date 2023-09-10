typedef char TElemType;
typedef struct TriTNode {
	TElemType data;
	struct TriTNode* lchild, * rchild,* parent;
}TriTNode, * TriTree;