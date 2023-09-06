#define MAXSIZE 100
typedef struct {
	float p;
	int e;
}Polynomial;

typedef struct {
	Polynomial* elem;
	int length;
}SqList;

typedef struct {
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct {
	Book* elem;
	int length;
}SqList;