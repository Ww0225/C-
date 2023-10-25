#include <iostream>
#define MAX_VERTEX_NUM 20
#define MaxInt 32767
#define MVNum 100
#define OK 1
#define ERROR 0
typedef int Status;
typedef char VerTexType;
typedef int InfoType;
typedef int ArcType;
typedef int OtherInfo;
typedef struct ArcBox {
	int tailvex, headvex;
	struct ArcBox* hlink, * tlink;
	InfoType* info;
}ArcBox;
typedef struct VexNode{
	VerTexType data;
	ArcBox* firstin, * firstout;
}VexNode;
typedef struct {
	VexNode xlist[MAX_VERTEX_NUM];
	int vexnum, arcnum;
}OLGraph;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;
typedef struct VNode{
	VerTexType data;
	ArcNode* firstarc;
}VNode,AdjList[MVNum];
typedef struct ArcNode{
	int adjvex;
	struct ArcNode* nextarc;
	OtherInfo info;
}ArcNode;
typedef struct {
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;
struct {
	VerTexType adjvex;
	ArcType lowcost;
}closedge[MVNum];
int LocateVex(AMGraph G, VerTexType u) {
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}
Status CreateUDN(AMGraph &G) {
	std::cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++)
		std::cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	for (int k = 0; k < G.vexnum; k++) {
		char v1, v2;
		int w;
		std::cin >> v1 >> v2 >> w;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arcs[i][j] = w;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}
Status CreateUDG(ALGraph& G) {
	std::cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		std::cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int k = 0; k < G.vexnum; k++) {
		VerTexType v1, v2;
		std::cin >> v1, v2;
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		ArcNode* p1 = new ArcNode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;
		G.vertices[i].firstarc = p1;
		ArcNode* p2 = new ArcNode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}
bool visited[MVNum];
void DFS_AM(AMGraph G, int v) {
	std::cout << v;
	visited[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		if (G.arcs[v][w] != 0 && !visited[w])
			DFS_AM(G, w);
	}
}
void DFS_AL(ALGraph G, int v) {
	std::cout << v;
	visited[v] = true;
	ArcNode* p = G.vertices->firstarc;
	while (p) {
		int w = p->adjvex;
		if (!visited[w])
			DFS_AL(G, w);
		p = p->nextarc;
	}
}
void BFS(Graph G, int v) {
	std::cout << v;
	visited[v] = true;
	InitQueue(Q);
	EnQueue(Q, v);
	while (!QueueEmpty(Q)) {
		DeQueue(Q, u);
		for (int w = FirstAdjVex(G, u); w >= 0; w = NextAdjVex(G, u, w)) {
			if (!visited[w])
				std::cout << w;
			visited[w] = true;
			EnQueue(Q, w);
		}
	}
}
void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
	int k = LocateVex(G, u);
	for (int j = 0; j < G.vexnum; j++) {
		if (j != k)
			closedge[j] = { u,G.arcs[k][j]};
	}
	closedge[k].lowcost = 0;
	for (int i = 1; i < G.vexnum; i++) {
		k = Min(closedge);
		VerTexType u0 = closedge[k].adjvex;
		VerTexType v0 = G.vexs[k];
		std::cout << u0 << v0;
		closedge[k].lowcost = 0;
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost)
				closedge[j] = { G.vexs[k],G.arcs[k][j] };
		}
	}
}