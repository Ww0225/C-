#include<stdlib.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char QElemType;
typedef struct QNode{
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
//�����еĳ�ʼ��
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return OK;
}
//����������
Status DestoryQueue(LinkQueue& Q) {
	while (Q.front) {
		QNode* p = new QNode;
		p = Q.front->next;
		free(Q.front);
		Q.front = p;
	}
	return OK;
}
//���������
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//�����г���
Status DeQueue(LinkQueue& Q,QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	QNode* p = Q.front->next;
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear == Q.front;
	delete p;
	return OK;
}
//�������еĶ�ͷԪ��
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
}