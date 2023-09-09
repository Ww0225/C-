#define MAXLEN 255
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;
//BFÀ„∑®
int Index_BF(SString S, SString T) {
	int i = 1;
	int j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}