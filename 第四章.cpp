#define MAXLEN 255
#define CHUNKSIZE 80
#define MAXSIZE 100
typedef struct {
	char ch[MAXLEN + 1];
	int length;
}SString;
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct CHUNK* next;
}Chunk;
typedef struct {
	Chunk* head, * tail;
	int curlen;
}LString;
int Index_BF(SString S, SString T, int pos) {
	int i = pos;
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
void get_next(SString T, int next[]) {
	int i = 1;
	next[1] = 0;
	int j = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
void get_nextval(SString T, int nextval[]) {
	int i = 1;
	nextval[1] = 0;
	int j = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			i++;
			j++;
			if (T.ch[i] != T.ch[j])
				nextval[i] = j;
			else
				nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}
int Index_KMP(SString S, SString T, int pos) {
	int i = pos;
	int j = 1;
	int next[MAXSIZE];
	get_next(T, next);
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else
			j = next[j];
	}
	if (j > T.length)
		return i - T.length;
	else
		return 0;
}