//#include <stdio.h>
//#include <stdlib.h>
//typedef int ElemType;
//typedef struct LinkNode {
//    ElemType data;
//    struct LinkNode* next;
//} LinkNode, * LinkList;
//// 创建单链表并返回头指针
//LinkList CreateList(ElemType arr[], int n) {
//    LinkList head = NULL;
//    LinkList tail = NULL;
//    for (int i = 0; i < n; ++i) {
//        LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//        if (newNode == NULL) {
//            printf("内存分配失败！\n");
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
//// 输出单链表中的元素值
//void PrintList(LinkList head) {
//    printf("单链表中的元素值为: ");
//    LinkNode* p = head;
//    while (p != NULL) {
//        printf("%d ", p->data);
//        p = p->next;
//    }
//    printf("\n");
//}
//// 在单链表的指定位置插入元素
//int InsertElem(LinkList* head, int pos, ElemType elem) {
//    LinkNode* p = *head;
//    int i = 1;
//    while (p != NULL && i < pos - 1) {
//        p = p->next;
//        ++i;
//    }
//    if (p == NULL || i > pos - 1) {
//        return 0; // 插入失败
//    }
//    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
//    if (newNode == NULL) {
//        printf("内存分配失败！\n");
//        exit(1);
//    }
//    newNode->data = elem;
//    newNode->next = p->next;
//    p->next = newNode;
//    return 1; // 插入成功
//}
//
//// 删除单链表中的指定位置元素
//int DeleteElem(LinkList* head, int pos) {
//    if (*head == NULL || pos < 1) {
//        return 0; // 删除失败
//    }
//    LinkNode* p = *head;
//    LinkNode* q = NULL;
//    int i = 1;
//    if (pos == 1) {
//        *head = p->next;
//        free(p);
//        return 1; // 删除成功
//    }
//    while (p != NULL && i < pos) {
//        q = p;
//        p = p->next;
//        ++i;
//    }
//    if (p == NULL || i > pos) {
//        return 0; // 删除失败
//    }
//    q->next = p->next;
//    free(p);
//    return 1; // 删除成功
//}
//
//int main() {
//    ElemType data[] = { 21, 18, 30, 75, 42, 56 };
//    int length = sizeof(data) / sizeof(data[0]);
//    LinkList myList = CreateList(data, length);
//    PrintList(myList);
//    // 在第3个位置插入67
//    int insertPos = 3;
//    int insertElem = 67;
//    int insertResult = InsertElem(&myList, insertPos, insertElem);
//    if (insertResult) {
//        printf("在第 %d 个位置插入 %d 成功！\n", insertPos, insertElem);
//        PrintList(myList);
//    }
//    else {
//        printf("在第 %d 个位置插入 %d 失败！\n", insertPos, insertElem);
//    }
//    // 删除第6个元素
//    int deletePos = 6;
//    int deleteResult = DeleteElem(&myList, deletePos);
//    if (deleteResult) {
//        printf("删除第 %d 个元素成功！\n", deletePos);
//        PrintList(myList);
//    }
//    else {
//        printf("删除第 %d 个元素失败！\n", deletePos);
//    }
//    return 0;
//}