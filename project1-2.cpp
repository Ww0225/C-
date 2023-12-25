//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElemType;
//typedef struct LinkNode {
//    ElemType data;
//    struct LinkNode* next;
//} LinkNode, * LinkList;
//// ��������������ͷָ��
//LinkList CreateList(ElemType arr[], int n) {
//    LinkList head = NULL;
//    LinkList tail = NULL;
//    for (int i = 0; i < n; ++i) {
//        LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//        if (newNode == NULL) {
//            printf("�ڴ����ʧ�ܣ�\n");
//            exit(1);
//        }
//        newNode->data = arr[i];
//        newNode->next = NULL;
//        if (head == NULL) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            tail = newNode;
//        }
//    }
//    return head;
//}
//// ����������е�Ԫ��ֵ
//void PrintList(LinkList head) {
//    printf("�������е�Ԫ��ֵΪ: ");
//    LinkNode* p = head;
//    while (p != NULL) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//// �ڵ������ָ��λ�ò���Ԫ��
//int InsertElem(LinkList* head, int pos, ElemType elem) {
//    LinkNode* p = *head;
//    int i = 1;
//    while (p != NULL && i < pos - 1) {
//        p = p->next;
//        ++i;
//    }
//    if (p == NULL || i > pos - 1) {
//        return 0; // ����ʧ��
//    }
//    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//    if (newNode == NULL) {
//        printf("�ڴ����ʧ�ܣ�\n");
//        exit(1);
//    }
//    newNode->data = elem;
//    newNode->next = p->next;
//    p->next = newNode;
//    return 1; // ����ɹ�
//}
//
//// ɾ���������е�ָ��λ��Ԫ��
//int DeleteElem(LinkList* head, int pos) {
//    if (*head == NULL || pos < 1) {
//        return 0; // ɾ��ʧ��
//    }
//    LinkNode* p = *head;
//    LinkNode* q = NULL;
//    int i = 1;
//    if (pos == 1) {
//        *head = p->next;
//        free(p);
//        return 1; // ɾ���ɹ�
//    }
//    while (p != NULL && i < pos) {
//        q = p;
//        p = p->next;
//        ++i;
//    }
//    if (p == NULL || i > pos) {
//        return 0; // ɾ��ʧ��
//    }
//    q->next = p->next;
//    free(p);
//    return 1; // ɾ���ɹ�
//}
//
//int main() {
//    ElemType data[] = { 21, 18, 30, 75, 42, 56 };
//    int length = sizeof(data) / sizeof(data[0]);
//    LinkList myList = CreateList(data, length);
//    PrintList(myList);
//    // �ڵ�3��λ�ò���67
//    int insertPos = 3;
//    int insertElem = 67;
//    int insertResult = InsertElem(&myList, insertPos, insertElem);
//    if (insertResult) {
//        printf("�ڵ� %d ��λ�ò��� %d �ɹ���\n", insertPos, insertElem);
//        PrintList(myList);
//    }
//    else {
//        printf("�ڵ� %d ��λ�ò��� %d ʧ�ܣ�\n", insertPos, insertElem);
//    }
//    // ɾ����6��Ԫ��
//    int deletePos = 6;
//    int deleteResult = DeleteElem(&myList, deletePos);
//    if (deleteResult) {
//        printf("ɾ���� %d ��Ԫ�سɹ���\n", deletePos);
//        PrintList(myList);
//    }
//    else {
//        printf("ɾ���� %d ��Ԫ��ʧ�ܣ�\n", deletePos);
//    }
//    return 0;
//}