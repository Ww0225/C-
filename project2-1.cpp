//#include <stdio.h>
//#define MAXSIZE 5
//typedef int ElemType;
//typedef struct {
//    ElemType stack[MAXSIZE];
//    int top;
//} QStackType;
//// 初始化栈
//void InitStack(QStackType* stack) {
//    stack->top = -1;
//}
//// 判断栈是否已满
//int IsFull(QStackType* stack) {
//    return stack->top == MAXSIZE - 1;
//}
//// 判断栈是否为空
//int IsEmpty(QStackType* stack) {
//    return stack->top == -1;
//}
//// 入栈操作
//int Push(QStackType* stack, ElemType elem) {
//    if (IsFull(stack)) {
//        return 0; // 入栈失败
//    }
//    stack->stack[++stack->top] = elem;
//    return 1; // 入栈成功
//}
//// 出栈操作
//int Pop(QStackType* stack, ElemType* elem) {
//    if (IsEmpty(stack)) {
//        return 0; // 出栈失败
//    }
//    *elem = stack->stack[stack->top--];
//    return 1; // 出栈成功
//}
//// 输出栈的元素
//void PrintStack(QStackType stack) {
//    printf("栈中元素为: ");
//    for (int i = 0; i <= stack.top; ++i) {
//        printf("%d ", stack.stack[i]);
//    }
//    printf("\n");
//}
//int main() {
//    QStackType stack1, stack2;
//    InitStack(&stack1);
//    InitStack(&stack2);
//    // 依次进栈数据为1,2,3,4,5，再全部出栈，输出出栈序列。
//    for (int i = 1; i <= 5; ++i) {
//        Push(&stack1, i);
//    }
//    printf("依次进栈数据为1,2,3,4,5，再全部出栈，出栈序列为: ");
//    while (!IsEmpty(&stack1)) {
//        ElemType elem;
//        Pop(&stack1, &elem);
//        printf("%d ", elem);
//    }
//    printf("\n");
//    // 先进栈 3,2,1，出栈 2 次，进栈 4,5,6,7，再全部出队，输出每次入栈，出栈序列。
//    printf("\n");
//    Push(&stack2, 3);
//    Push(&stack2, 2);
//    Push(&stack2, 1);
//    printf("先进栈3,2,1，出栈2次，进栈4,5,6,7，再全部出栈，出栈序列为: ");
//    for (int i = 0; i < 2; ++i) {
//        ElemType elem;
//        Pop(&stack2, &elem);
//        printf("%d ", elem);
//    }
//    Push(&stack2, 4);
//    Push(&stack2, 5);
//    Push(&stack2, 6);
//    Push(&stack2, 7);
//    printf("\n每次入栈出栈序列为: ");
//    while (!IsEmpty(&stack2)) {
//        PrintStack(stack2);
//        ElemType elem;
//        Pop(&stack2, &elem);
//    }
//    return 0;
//}