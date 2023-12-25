//#include <stdio.h>
//#define MAXSIZE 100
//typedef int ElemType;
//typedef struct {
//    ElemType data[MAXSIZE];
//    int length;
//} SqList;
//// 初始化顺序表
//void InitList(SqList* L) {
//    L->length = 0;
//}
//// 输出顺序表中的元素值
//void PrintList(SqList L) {
//    printf("顺序表中的元素值为: ");
//    for (int i = 0; i < L.length; ++i) {
//        printf("%d ", L.data[i]);
//    }
//    printf("\n");
//}
//// 在顺序表的指定位置插入元素
//int InsertElem(SqList* L, int pos, ElemType elem) {
//    if (pos < 1 || pos > L->length + 1 || L->length == MAXSIZE) {
//        return 0; // 插入失败
//    }
//    for (int i = L->length - 1; i >= pos - 1; --i) {
//        L->data[i + 1] = L->data[i];
//    }
//    L->data[pos - 1] = elem;
//    L->length++;
//    return 1; // 插入成功
//}
//// 从顺序表中删除指定位置的元素
//int DeleteElem(SqList* L, int pos) {
//    if (pos < 1 || pos > L->length) {
//        return 0; // 删除失败
//    }
//    for (int i = pos; i < L->length; ++i) {
//        L->data[i - 1] = L->data[i];
//    }
//    L->length--;
//    return 1; // 删除成功
//}
//int main() {
//    SqList myList;
//    InitList(&myList);
//    // 创建顺序表并输出元素值
//    for (int i = 0; i < 6; ++i) {
//        myList.data[i] = i + 1;
//        myList.length++;
//    }
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
//
//    return 0;
//}