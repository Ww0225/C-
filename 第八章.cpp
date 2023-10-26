#define MAXSIZE 20
typedef int KeyType;
typedef struct {
	KeyType key;
	//InfoType otherinfo;
}RedType;
typedef struct{
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
void InsertSort(SqList& L) {
	int i = 0;
	int j = 0;
	for (i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0].key = L.r[i].key;
			for (j = i - 2; L.r[0].key < L.r[j].key; j--)
				L.r[j + 1] = L.r[j];
		}
		L.r[j + 1].key = L.r[0].key;
	}
}
void BInsertSort(SqList& L) {
	int mid, high, low,i,j = 0;
	for (i = 2;i<=L.length; i++) {
		L.r[0].key = L.r[i].key;
		low = 1;
		high = i - 1;
		while (low <= high) {
			mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)
				high = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--)
			L.r[j + 1] = L.r[j];
		L.r[high + 1] = L.r[0];
	}
}
//void Bubble_sort(SqList& L) {
//	int i, j;
//	RedType tmp;
//	for (i = 1; i <= L.length-1; i++) {
//		for (j = 1; j <= L.length - i; j++) {
//			if (L.r[j].key > L.r[j + 1].key) {
//				tmp = L.r[j];
//				L.r[j] = L.r[j + 1];
//				L.r[j + 1] = tmp;
//			}
//		}
//	}
//}
//¸Ä½ø
void Bubble_sort(SqList& L) {
	int i, j;
	int flag = 1;
	RedType tmp;
	for (i = 1; i <= L.length - 1&&flag==1; i++) {
		flag = 0;
		for (j = 1; j <= i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;
				tmp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = tmp;
			}
		}
	}
}
int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	KeyType pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey)
			high--;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key <= pivotkey)
			low++;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void QSort(SqList& L, int low, int high) {
	int pivotloc;
	if (low < high) {
		pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}