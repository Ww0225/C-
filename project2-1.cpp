//#include <stdio.h>
//#define MAXSIZE 5
//typedef int ElemType;
//typedef struct {
//    ElemType stack[MAXSIZE];
//    int top;
//} QStackType;
//// ��ʼ��ջ
//void InitStack(QStackType* stack) {
//    stack->top = -1;
//}
//// �ж�ջ�Ƿ�����
//int IsFull(QStackType* stack) {
//    return stack->top == MAXSIZE - 1;
//}
//// �ж�ջ�Ƿ�Ϊ��
//int IsEmpty(QStackType* stack) {
//    return stack->top == -1;
//}
//// ��ջ����
//int Push(QStackType* stack, ElemType elem) {
//    if (IsFull(stack)) {
//        return 0; // ��ջʧ��
//    }
//    stack->stack[++stack->top] = elem;
//    return 1; // ��ջ�ɹ�
//}
//// ��ջ����
//int Pop(QStackType* stack, ElemType* elem) {
//    if (IsEmpty(stack)) {
//        return 0; // ��ջʧ��
//    }
//    *elem = stack->stack[stack->top--];
//    return 1; // ��ջ�ɹ�
//}
//// ���ջ��Ԫ��
//void PrintStack(QStackType stack) {
//    printf("ջ��Ԫ��Ϊ: ");
//    for (int i = 0; i <= stack.top; ++i) {
//        printf("%d ", stack.stack[i]);
//    }
//    printf("\n");
//}
//int main() {
//    QStackType stack1, stack2;
//    InitStack(&stack1);
//    InitStack(&stack2);
//    // ���ν�ջ����Ϊ1,2,3,4,5����ȫ����ջ�������ջ���С�
//    for (int i = 1; i <= 5; ++i) {
//        Push(&stack1, i);
//    }
//    printf("���ν�ջ����Ϊ1,2,3,4,5����ȫ����ջ����ջ����Ϊ: ");
//    while (!IsEmpty(&stack1)) {
//        ElemType elem;
//        Pop(&stack1, &elem);
//        printf("%d ", elem);
//    }
//    printf("\n");
//    // �Ƚ�ջ 3,2,1����ջ 2 �Σ���ջ 4,5,6,7����ȫ�����ӣ����ÿ����ջ����ջ���С�
//    printf("\n");
//    Push(&stack2, 3);
//    Push(&stack2, 2);
//    Push(&stack2, 1);
//    printf("�Ƚ�ջ3,2,1����ջ2�Σ���ջ4,5,6,7����ȫ����ջ����ջ����Ϊ: ");
//    for (int i = 0; i < 2; ++i) {
//        ElemType elem;
//        Pop(&stack2, &elem);
//        printf("%d ", elem);
//    }
//    Push(&stack2, 4);
//    Push(&stack2, 5);
//    Push(&stack2, 6);
//    Push(&stack2, 7);
//    printf("\nÿ����ջ��ջ����Ϊ: ");
//    while (!IsEmpty(&stack2)) {
//        PrintStack(stack2);
//        ElemType elem;
//        Pop(&stack2, &elem);
//    }
//    return 0;
//}