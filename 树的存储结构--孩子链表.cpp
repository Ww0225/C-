#define MAX_TREE_SIZE 100
typedef char TElemType;
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
	int r, n;
}CTree;