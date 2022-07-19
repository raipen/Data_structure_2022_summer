#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 2002
typedef enum {LESS,GREATER,EQUAL} CompareInt;
typedef struct {
    int coef;
    int expon;
} Polynomial;

Polynomial terms[MAX_TERMS];
int avail = 0;

int readPolynomialFromFile(FILE* file);
int addPolynomial(int startA, int endA, int startB, int endB);
CompareInt compareInt(int a,int b);
void printPolynomial(const char* polyname,int start,int end);

int main(void){
    int startA,startB,startC,endA,endB,endC;
    startA = avail;
    endA = startB = readPolynomialFromFile(fopen("a.txt", "r"));
    endB = startC = readPolynomialFromFile(fopen("b.txt", "r"));
    endC = addPolynomial(startA,endA,startB,endB);

    printPolynomial("A",startA,endA);
    printPolynomial("B",startB,endB);
    puts("");
    printPolynomial("C",startC,endC);
    return 0;
}

int readPolynomialFromFile(FILE* file){
    for(;fscanf(file, "%d %d", &terms[avail].coef,&terms[avail].expon)==2;avail++);
    return avail;
}

int addPolynomial(int startA, int endA, int startB, int endB){
    while(startA < endA && startB < endB){
        switch(compareInt(terms[startA].expon,terms[startB].expon)){
            case LESS:
                terms[avail++]=terms[startB++];
                break;
            case GREATER:
                terms[avail++]=terms[startA++];
                break;
            case EQUAL:
                terms[avail]=terms[startA++];
                terms[avail++].coef +=terms[startB++].coef;
                if(!terms[avail-1].coef) avail--;
                break;
        }
    }
    while(startA<endA)
        terms[avail++]=terms[startA++];
    while(startB < endB)
        terms[avail++]=terms[startB++];
    return avail;
}

CompareInt compareInt(int a,int b){
    if(a<b) return LESS;
    else if(a>b) return GREATER;
    return EQUAL;
}

void printPolynomial(const char* polyname,int start,int end){
    printf("%s(x): ", polyname);
    printf("%d^%d",terms[start].coef,terms[start].expon);
    for(start++;start<end;start++)
        printf(" + %d^%d",terms[start].coef,terms[start].expon);
    printf("\n");
}