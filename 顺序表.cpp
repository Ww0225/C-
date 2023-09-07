#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef char ElemType;
typedef int Status;
typedef struct {
	ElemType* elem;
	int length;
}SqList;
typedef struct {
	ElemType* elem;
	int length;
}List;
//顺序表的初始化
Status InitList(SqList& L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem)
		return OVERFLOW;
	L.length = 0;
	return OK;
}
//顺序表的取值
Status GetElem(SqList L, int i, ElemType& e) {
	if (i<1 || i>L.length)
		return ERROR;
	e = L.elem[i - 1];
	return OK;
}
//顺序表的查找
int LocateElem(SqList L, ElemType e) {
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)
			return i + 1;
	}
	return 0;
}
//顺序表的插入
Status ListInsert(SqList& L, int i, ElemType e) {
	if (i<1 || i>L.length)
		return ERROR;
	if (L.length == MAXSIZE)
		return ERROR;
	for (int j = L.length - 1; j > i; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return OK;
}
//顺序表的删除
Status ListDelete(SqList& L, int i) {
	if (i<1 || i>L.length)
		return ERROR;
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
//顺序表的销毁
void DestoryList(SqList& L) {
	if (!L.elem)
		delete L.elem;
}
//顺序表的清空
void ClearList(SqList& L) {
	L.length = 0;
}
//顺序表是否为空
int IsEmpty(SqList L) {
	if (L.length == 0)
		return 1;
	else
		return 0;
}
//线性表的合并
//void union_L(List& La, List Lb) {
//	La_len = ListLength(La);
//	Lb_len = ListLength(Lb);
//	for (int i = 1; i <= Lb_len; i++) {
//		GetElem(Lb, i, e);
//		ListInsert(&La, La++, e);
//	}
//}
//顺序有序表的合并
void MergeList_Sq(SqList La, SqList Lb, SqList& Lc) {
	Lc.length = La.length + Lb.length;
	Lc.elem = new ElemType[Lc.length];
	ElemType* pa = La.elem;
	ElemType* pb = Lb.elem;
	ElemType* pc = Lc.elem;
	ElemType* pa_last = La.elem + La.length - 1;
	ElemType* pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last) {
		if (*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while (pa <= pa_last)
		*pc++ = *pa++;
	while (pb <= pb_last)
		*pc++ = *pb++;
}