typedef char KeyType;
typedef struct {
	KeyType key;			//关键字域
}ElemType;
typedef struct {
	ElemType* R;			//基地址
	int length;				//表长
}SSTable;
SSTable ST;
int Search_Bin(SSTable ST, KeyType key) {
	int low = 1;
	int high = ST.length;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (ST.R[mid].key == key) {
			return mid;
		}
		else if (ST.R[mid].key > key) {
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return 0;
}