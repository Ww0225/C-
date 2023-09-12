typedef char** HuffmanCode;
typedef struct {
	int weight;
	int parent, lch, rch;
}HTNode, * HuffmanTree;
void CreateHuffmanCode(HuffmanTree HT,HuffmanCode& HC,int n) {
	HuffmanCode HC = new char*[n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; i++) {
		int start = n - 1;
		int c = i;
		int f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lch == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HT[i], &cd[start]);
	}
	delete cd;
}