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
//ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front  = Q.rear = 0;
	return OK;
}
//ѭ�����еĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//ѭ�����е����
Status EnQueue(SqQueue& Q, QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//ѭ�����еĳ���
Status DeQueue(SqQueue& Q,QElemType& e) {
	if (Q.rear == Q.front)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//ȡѭ�����еĶ�ͷԪ��
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}