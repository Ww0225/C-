#include<stdlib.h>
#include <iostream>
#define MAXQSIZE 100
#define OK 1
#define MVNum 100
#define ERROR 0
#define OVERFLOW -1
bool visited[MVNum];
typedef int Status;
typedef char QElemType;
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum, arcnum;
}AMGraph;
typedef struct {
	QElemType* base;
	int front;
	int rear;
}SqQueue;
//循环队列的初始化
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
//循环队列的入队
Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//循环队列的出队
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.rear == Q.front)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//广度优先遍历
void BFS(AMGraph G, int v) {
	std::cout<<v;
	SqQueue Q;
	InitQueue(Q);
	EnQueue(Q, v);
	while (Q.front!=Q.rear) {
		QElemType u;
		DeQueue(Q, u);
		for (int w = FirstAdjVex(G, u); w > 0; w = NextAdjVex(G, u, w)) {
			if (!visited[w]){
				std::cout << w;
				visited[w] = true;
				EnQueue(Q, w);
				}
		}
	}
}