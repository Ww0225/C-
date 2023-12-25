//#include <stdio.h>
//#define MAXSIZE 6
//typedef int ElemType;
//typedef struct {
//    ElemType data[MAXSIZE];
//    int front;
//    int rear;
//} SeQueue;
//// ��ʼ������
//void InitQueue(SeQueue* queue) {
//    queue->front = queue->rear = 0;
//}
//// �ж϶����Ƿ�Ϊ��
//int IsEmpty(SeQueue* queue) {
//    return queue->front == queue->rear;
//}
//// �ж϶����Ƿ�����
//int IsFull(SeQueue* queue) {
//    return (queue->rear + 1) % MAXSIZE == queue->front;
//}
//// ��Ӳ���
//int EnQueue(SeQueue* queue, ElemType elem) {
//    if (IsFull(queue)) {
//        return 0; // ���ʧ��
//    }
//    queue->data[queue->rear] = elem;
//    queue->rear = (queue->rear + 1) % MAXSIZE;
//    return 1; // ��ӳɹ�
//}
//// ���Ӳ���
//int DeQueue(SeQueue* queue, ElemType* elem) {
//    if (IsEmpty(queue)) {
//        return 0; // ����ʧ��
//    }
//    *elem = queue->data[queue->front];
//    queue->front = (queue->front + 1) % MAXSIZE;
//    return 1; // ���ӳɹ�
//}
//// ��������е�Ԫ��
//void PrintQueue(SeQueue* queue) {
//    printf("�����е�Ԫ��Ϊ: ");
//    int i = queue->front;
//    while (i != queue->rear) {
//        printf("%d ", queue->data[i]);
//        i = (i + 1) % MAXSIZE;
//    }
//    printf("\n");
//}
//int main() {
//    SeQueue myQueue;
//    InitQueue(&myQueue);
//    // �����������Ϊ1,2,3,4,5����ȫ�����ӣ�������Ӷ������С�
//    for (int i = 1; i <= 5; ++i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("�����������Ϊ1,2,3,4,5����ȫ�����ӣ����Ӷ�������Ϊ: ");
//    while (!IsEmpty(&myQueue)) {
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//        printf("%d ", elem);
//    }
//    printf("\n");
//    // ���������3,2,1������2�Σ����4,5,6,7������������ݳ��ӣ����ÿ����Ӻͳ������С�
//    printf("\n");
//    for (int i = 3; i >= 1; --i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("�����3,2,1������2�Σ����4,5,6,7������������ݳ��ӣ����Ӷ�������Ϊ: ");
//    for (int i = 0; i < 2; ++i) {
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//        printf("%d ", elem);
//    }
//    for (int i = 4; i <= 7; ++i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("\nÿ����ӳ�������Ϊ: ");
//    while (!IsEmpty(&myQueue)) {
//        PrintQueue(&myQueue);
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//    }
//    return 0;
//}
