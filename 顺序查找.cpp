typedef char KeyType;
typedef struct {
	KeyType key;			//关键字域
}ElemType;
typedef struct {
	ElemType* R;			//基地址
	int length;				//表长
}SSTable;
SSTable ST;
//顺序查找
int Search_Seq(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int i = 0;
	for (i = ST.R[i].key != key; i--;)
	return i;
}
//其他形式
int Search_Seq(SSTable ST, KeyType key) {
	int i = 0;
	for (i = ST.length; ST.R[i].key != key; i--)
		if (i <= 0)
			break;
	if (i > 0)
		return i;
	else
		return 0;
}