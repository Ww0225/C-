//#include <stdio.h>
//#define MAXSIZE 100
//typedef int ElemType;
//typedef struct {
//    ElemType data[MAXSIZE];
//    int length;
//} SqList;
//// ��ʼ��˳���
//void InitList(SqList* L) {
//    L->length = 0;
//}
//// ���˳����е�Ԫ��ֵ
//void PrintList(SqList L) {
//    printf("˳����е�Ԫ��ֵΪ: ");
//    for (int i = 0; i < L.length; ++i) {
//        printf("%d ", L.data[i]);
//    }
//    printf("\n");
//}
//// ��˳����ָ��λ�ò���Ԫ��
//int InsertElem(SqList* L, int pos, ElemType elem) {
//    if (pos < 1 || pos > L->length + 1 || L->length == MAXSIZE) {
//        return 0; // ����ʧ��
//    }
//    for (int i = L->length - 1; i >= pos - 1; --i) {
//        L->data[i + 1] = L->data[i];
//    }
//    L->data[pos - 1] = elem;
//    L->length++;
//    return 1; // ����ɹ�
//}
//// ��˳�����ɾ��ָ��λ�õ�Ԫ��
//int DeleteElem(SqList* L, int pos) {
//    if (pos < 1 || pos > L->length) {
//        return 0; // ɾ��ʧ��
//    }
//    for (int i = pos; i < L->length; ++i) {
//        L->data[i - 1] = L->data[i];
//    }
//    L->length--;
//    return 1; // ɾ���ɹ�
//}
//int main() {
//    SqList myList;
//    InitList(&myList);
//    // ����˳������Ԫ��ֵ
//    for (int i = 0; i < 6; ++i) {
//        myList.data[i] = i + 1;
//        myList.length++;
//    }
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
//
//    return 0;
//}