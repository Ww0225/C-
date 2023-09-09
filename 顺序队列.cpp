#include<stdlib.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char QElemType;
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
	Q.front  = Q.rear = 0;
	return OK;
}
//循环队列的长度
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
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
Status DeQueue(SqQueue& Q,QElemType& e) {
	if (Q.rear == Q.front)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//取循环队列的队头元素
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}