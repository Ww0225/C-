#include<stdio.h>
typedef struct {
	int weight;
	int parent, lch, rch;
}HTNode,*HuffmanTree;
//哈夫曼树的构造
void CreateHuffmanTree(HuffmanTree& HT, int n) {
	//哈夫曼树的初始化
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; i++) {
		HT[i].lch = 0;
		HT[i].rch = 0;
		HT[i].parent = 0;
	}
	for (int i = 1; i <= n; i++) {
		scanf(&HT[i].weight);
	}
	//初始化结束，开始构造
	for (int i = n + 1; i <= m; i++) {
		Select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}