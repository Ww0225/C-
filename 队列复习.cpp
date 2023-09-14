#include<stdlib.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char QElemType;
typedef struct {
	QElemType* base;				//存储空间的基地址
	int front;						//头指针
	int rear;						//尾指针
}SqQueue;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;					//队头指针
	QueuePtr rear;					//队尾指针
}LinkQueue;
//循环队列的初始化
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
//循环列表的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//循环列表的入队
Status EnQueue(SqQueue& Q,QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//循环列表的出队
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//循环列表取队头元素
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
//链队的初始化
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front = NULL;
	return OK;
}
//链队的入队
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//链队的出队
Status DeQueue(LinkQueue& Q, QElemType e) {
	if (Q.front == Q.rear)
		return ERROR;
	QNode* p = Q.front->next;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	delete p;
	return OK;
}
//链队取队头元素
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
}