#include<stdio.h>
typedef struct {
	float realpart;
	float imagpart;
}Complex;

void assign(Complex* A, float real, float imag) {
	A->realpart = real;
	A->imagpart = imag;
}
void add(Complex* C, Complex A, Complex B) {
	C->realpart = A.realpart + B.realpart;
	C->imagpart = A.imagpart + B.imagpart;
}
void minus(Complex* A, float real, float imag) {

}
void multiply(Complex* C, Complex A, Complex B) {
	C->realpart = A.realpart * B.realpart;
	C->imagpart = A.imagpart * B.imagpart;
}
void divide(Complex* A, float real, float imag) {

}
