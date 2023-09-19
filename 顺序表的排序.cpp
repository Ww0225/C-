#define MAXSIZE 20
typedef int KeyType;
typedef InfoType;
typedef struct {
	KeyType key;
	InfoType otherinfo;
}RedType;
typedef struct {
	RedType r[MAXSIZE + 1];
	int length;
}SqList;
//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(SqList& L) {
	int i = 0;
	int j = 0;
	for (int i = 2; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - 1].key) {
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].key < L.r[j].key; j--) {
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];
		}
	}
}
//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(SqList& L) {
	int i = 0;
	int j = 0;
	for (int i = 2; i <= L.length; i++) {
		L.r[0] = L.r[i];
		int low = 1;
		int high = i - 1;
		while (low <= high) {
			int mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key) {
				high = mid - 1;
			}
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= high + 1; j--) {
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}
//œ£∂˚≈≈–Ú
void ShellSort(SqList& L, int dlta[], int t) {
	for (int k = 0; k < t; k++) {
		ShellInsert(L, dlta[k]);
	}
}
void ShellInsert(SqList& L, int dk) {
	int i = 0;
	int j = 0;
	for (i = dk + 1; i <= L.length; i++) {
		if (L.r[i].key < L.r[i - dk].key) {
			L.r[0] = L.r[i];
			for (j = i - dk; j > 0 && L.r[0].key < L.r[j].key; j = j - dk) {
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}
//√∞≈›≈≈–Ú(…˝–Ú)
void BubbleSort(SqList& L) {
	int i = 0;
	int j = 0;
	int flag = 1;
	RedType tmp;
	for (i = 1; i <= L.length - 1&&flag==1; i++) {
		flag = 0;
		for (j = 1; j <= L.length - i; j++) {
			if (L.r[j].key > L.r[j + 1].key) {
				flag = 1;
				tmp = L.r[j];
				L.r[j] = L.r[j + 1];
				L.r[j + 1] = tmp;
			}
		}
	}
}
//øÏÀŸ≈≈–Ú
void QSort(SqList& L, int low, int high) {
	if (low < high) {
		int pivotloc = Partition(L, low, high);
		QSort(L, low, pivotloc - 1);
		QSort(L, pivotloc + 1, high);
	}
}
int Partition(SqList& L, int low, int high) {
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high) {
		while (low < high && L.r[high].key >= pivotkey); {
			high--;
		}
		L.r[low] = L.r[high];
		while (low < high && L.r[high].key <= pivotkey); {
			low++;
		}
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}