#define MAX_TREE_SIZE 100
typedef char TElemType;
typedef struct PTNode {
	TElemType data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r, n;
}PTree;