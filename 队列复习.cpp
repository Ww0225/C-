#include<stdlib.h>
#define MAXQSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef char QElemType;
typedef struct {
	QElemType* base;				//�洢�ռ�Ļ���ַ
	int front;						//ͷָ��
	int rear;						//βָ��
}SqQueue;
typedef struct QNode {
	QElemType data;
	struct QNode* next;
}QNode,*QueuePtr;
typedef struct {
	QueuePtr front;					//��ͷָ��
	QueuePtr rear;					//��βָ��
}LinkQueue;
//ѭ�����еĳ�ʼ��
Status InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXQSIZE];
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
//ѭ���б�ĳ���
int QueueLength(SqQueue Q) {
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
//ѭ���б�����
Status EnQueue(SqQueue& Q,QElemType e) {
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
//ѭ���б�ĳ���
Status DeQueue(SqQueue& Q, QElemType& e) {
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
//ѭ���б�ȡ��ͷԪ��
QElemType GetHead(SqQueue Q) {
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
//���ӵĳ�ʼ��
Status InitQueue(LinkQueue& Q) {
	Q.front = Q.rear = new QNode;
	Q.front = NULL;
	return OK;
}
//���ӵ����
Status EnQueue(LinkQueue& Q, QElemType e) {
	QNode* p = new QNode;
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
//���ӵĳ���
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
//����ȡ��ͷԪ��
QElemType GetHead(LinkQueue Q) {
	if (Q.front != Q.rear)
		return Q.front->next->data;
}