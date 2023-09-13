#include<stdio.h>
#include <iostream>
#define MaxInt 32767
#define MVNum 100
#define OK 1
bool visited[MVNum];
typedef int Status;
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;
//采用邻接矩阵表示图的深度优先搜索遍历
void DFS(AMGraph G, int v) {
	std::cout << v;
	visited[v] = true;
	for (int w = 0; w < G.vexnum; w++) {
		if (G.arcs[v][w] != 0 && !visited[w]) {
			DFS(G, w);
		}
	}
}