typedef char KeyType;
typedef struct {
	KeyType key;			//�ؼ�����
}ElemType;
typedef struct {
	ElemType* R;			//����ַ
	int length;				//��
}SSTable;
SSTable ST;
//˳�����
int Search_Seq(SSTable ST, KeyType key) {
	ST.R[0].key = key;
	int i = 0;
	for (i = ST.R[i].key != key; i--;)
	return i;
}
//������ʽ
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