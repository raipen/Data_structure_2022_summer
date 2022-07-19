#include <stdio.h>
#include <stdlib.h>

struct monomial{
    int coefficient;
    int exponent;
    struct monomial* next;
};
typedef struct monomial* Polynomial;
typedef enum {LESS,GREATER,EQUAL} CompareInt;

Polynomial readPolynomialFromFile(FILE* file);
Polynomial readMonomialFromFile(FILE* file);
Polynomial addPolynomial(Polynomial A,Polynomial B);
Polynomial findLargestExpoment(Polynomial* A,Polynomial* B);
Polynomial popFirstMonomial(Polynomial* A);
Polynomial addFirstMonomial(Polynomial* A,Polynomial* B);
CompareInt compareInt(int a,int b);
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
    Polynomial polyHead = (Polynomial) malloc(sizeof(*polyHead));
    for(Polynomial last = polyHead;last;last = last->next)
        last->next = readMonomialFromFile(file);
    return polyHead->next;
}

Polynomial readMonomialFromFile(FILE* file){
    Polynomial temp = (Polynomial) malloc(sizeof(*temp));
    if(fscanf(file, "%d %d", &temp->coefficient,&temp->exponent)!=2)
        return NULL;
    temp->next = NULL;
    return temp;
}

Polynomial addPolynomial(Polynomial A,Polynomial B){
    Polynomial C = (Polynomial) malloc(sizeof(*C));
    for(Polynomial last = C;last;last = last->next&&!last->next->coefficient?last:last->next)
        last->next = findLargestExpoment(&A,&B);
    return C->next;
}

Polynomial findLargestExpoment(Polynomial* A,Polynomial* B){
    if(!((*B)||(*A))) return NULL;
    if(!(*B))
        return popFirstMonomial(A);
    if(!(*A))
        return popFirstMonomial(B);
    switch(compareInt((*A)->exponent,(*B)->exponent)){
        case LESS:
            return popFirstMonomial(B);
        case GREATER:
            return popFirstMonomial(A);
        case EQUAL:
            return addFirstMonomial(A,B);
    }
}

Polynomial popFirstMonomial(Polynomial* A){
    Polynomial temp = (Polynomial) malloc(sizeof(*temp));
    temp->coefficient = (*A)->coefficient;
    temp->exponent = (*A)->exponent;
    (*A) = (*A)->next;
    return temp;
}

Polynomial addFirstMonomial(Polynomial* A,Polynomial* B){
    Polynomial temp = (Polynomial) malloc(sizeof(*temp));
    temp->coefficient = (*A)->coefficient+(*B)->coefficient;
    temp->exponent = (*A)->exponent;
    (*A) = (*A)->next;
    (*B) = (*B)->next;
    return temp;
}

CompareInt compareInt(int a,int b){
    if(a<b) return LESS;
    else if(a>b) return GREATER;
    return EQUAL;
}

void printPolynomial(const char* polyname,Polynomial poly){
    if(!poly) return;
    printf("%s(x): ", polyname);
    for(;poly->next;poly = poly->next)
        printf("%d^%d + ",poly->coefficient,poly->exponent);
    printf("%d^%d\n",poly->coefficient,poly->exponent);
}
