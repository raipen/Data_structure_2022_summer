#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 1001
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN_VALUE 0xFFFFFFFF
typedef struct{
    int degree;
    int coef[MAX_DEGREE];
}Polynomial;

Polynomial readPolynomialFromFile(FILE* file);
Polynomial addPolynomial(Polynomial A,Polynomial B);
void printPolynomial(const char* polyname,Polynomial poly);

int main(void){
    Polynomial A = readPolynomialFromFile(fopen("a.txt", "r"));
    Polynomial B = readPolynomialFromFile(fopen("b.txt", "r"));
    Polynomial C = addPolynomial(A,B);

    printPolynomial("A",A);
    printPolynomial("B",B);
    puts("");
    printPolynomial("C",C);
    return 0;
}

Polynomial readPolynomialFromFile(FILE* file){
    Polynomial temp={0};
    temp.degree = MIN_VALUE;
    int coefficient,exponent;
    while(fscanf(file, "%d %d", &coefficient,&exponent)==2){
        temp.coef[exponent]=coefficient;
        temp.degree = MAX(temp.degree,exponent);
    }
    return temp;
}

Polynomial addPolynomial(Polynomial A,Polynomial B){
    Polynomial temp={0};
    temp.degree = MIN_VALUE;
    for(int i=MAX(A.degree,B.degree);i>=0;i--){
        temp.coef[i]=A.coef[i]+B.coef[i];
        if(temp.coef[i]&&temp.degree==MIN_VALUE)
            temp.degree = i;
    }
    return temp;
}

void printPolynomial(const char* polyname,Polynomial poly){
    printf("%s(x): ", polyname);
    printf("%d^%d",poly.coef[poly.degree],poly.degree);
    for(int i=poly.degree-1;i>=0;i--)
        if(poly.coef[i])
        printf(" + %d^%d",poly.coef[i],i);
    printf("\n");
}