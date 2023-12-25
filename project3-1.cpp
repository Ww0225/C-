//#include <stdio.h>
//#define MAXSIZE 6
//typedef int ElemType;
//typedef struct {
//    ElemType data[MAXSIZE];
//    int front;
//    int rear;
//} SeQueue;
//// 初始化队列
//void InitQueue(SeQueue* queue) {
//    queue->front = queue->rear = 0;
//}
//// 判断队列是否为空
//int IsEmpty(SeQueue* queue) {
//    return queue->front == queue->rear;
//}
//// 判断队列是否已满
//int IsFull(SeQueue* queue) {
//    return (queue->rear + 1) % MAXSIZE == queue->front;
//}
//// 入队操作
//int EnQueue(SeQueue* queue, ElemType elem) {
//    if (IsFull(queue)) {
//        return 0; // 入队失败
//    }
//    queue->data[queue->rear] = elem;
//    queue->rear = (queue->rear + 1) % MAXSIZE;
//    return 1; // 入队成功
//}
//// 出队操作
//int DeQueue(SeQueue* queue, ElemType* elem) {
//    if (IsEmpty(queue)) {
//        return 0; // 出队失败
//    }
//    *elem = queue->data[queue->front];
//    queue->front = (queue->front + 1) % MAXSIZE;
//    return 1; // 出队成功
//}
//// 输出队列中的元素
//void PrintQueue(SeQueue* queue) {
//    printf("队列中的元素为: ");
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
//    // 依次入队数据为1,2,3,4,5，再全部出队，输出出队队列序列。
//    for (int i = 1; i <= 5; ++i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("依次入队数据为1,2,3,4,5，再全部出队，出队队列序列为: ");
//    while (!IsEmpty(&myQueue)) {
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//        printf("%d ", elem);
//    }
//    printf("\n");
//    // 先入队数据3,2,1，出队2次，入队4,5,6,7，最后所有数据出队，输出每次入队和出队序列。
//    printf("\n");
//    for (int i = 3; i >= 1; --i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("先入队3,2,1，出队2次，入队4,5,6,7，最后所有数据出队，出队队列序列为: ");
//    for (int i = 0; i < 2; ++i) {
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//        printf("%d ", elem);
//    }
//    for (int i = 4; i <= 7; ++i) {
//        EnQueue(&myQueue, i);
//    }
//    printf("\n每次入队出队序列为: ");
//    while (!IsEmpty(&myQueue)) {
//        PrintQueue(&myQueue);
//        ElemType elem;
//        DeQueue(&myQueue, &elem);
//    }
//    return 0;
//}
