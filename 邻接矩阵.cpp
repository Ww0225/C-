#include<stdio.h>
#define MaxInt 32767
#define MVNum 100
#define OK 1
typedef int Status;
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;
//在图中查找顶点
int LocateVex(AMGraph G,VerTexType u) {
	int i;
	for (i = 0; i < G.vexnum; i++) {
		if (u == G.vexs[i])
			return i;
	}
	return -1;
}
//采用邻接矩阵表示法创建无向网
Status CreateUDN(AMGraph& G) {
	scanf(&G.vexnum);
	scanf(&G.arcnum);
	for (int i = 0; i < G.vexnum; i++) {
		scanf(&G.vexs[i]);
	}
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	for (int k = 0; k < G.arcnum; k++) {
		VerTexType v1;
		VerTexType v2;
		int weight;
		scanf(&v1);
		scanf(&v2);
		scanf(&weight);
		int i = LocateVex(G, v1);
		int j = LocateVex(G, v2);
		G.arcs[i][j] = weight;
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}