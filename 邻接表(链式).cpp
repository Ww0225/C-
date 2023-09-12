#include<stdio.h>
#define MVNum 100
#define OK 1
typedef int Status;
typedef int VerTexType;
typedef int OtherInfo;
typedef struct ArcNode {
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;
typedef struct VNode {
	VerTexType data;
	ArcNode* firstarc;
}VNode,AdjList[MVNum];
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGragh;
//在图中查找顶点
int LocateVex(ALGragh G, VerTexType u) {
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vertices[i].data)
			return i;
	}
	return -1;
}
//邻接法创建无向图
Status CreateUDG(ALGragh& G) {
	scanf(&G.arcnum);
	scanf(&G.vexnum);
	for (int i = 0; i < G.vexnum; i++) {
		scanf(&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.arcnum; k++) {
		VerTexType v1;
		VerTexType v2;
		scanf(&v1);
		scanf(&v2);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		ArcNode* p2 = new ArcNode;
		p2->adjvex = j;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}