// 더하는 부분 완성하지 못함
#define _CRT_SECURE_NO_WARNINGS
#define MAX 500
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int co[MAX];
    int ex[MAX];
}poly;

AddPolynomial(poly str1, poly str2)
{
    int i = 0, j = 0;
    while (str1.co[i] != 0 && str2.co[j] != 0) {
        if (str1.ex[i] == str2.ex[j]) {
            str1.co[i] += str2.co[j];
            i++;
            j++;
        }
        else if (str1.ex[i] > str2.ex[j]) {

        }
    }


}

void main()
{
    poly str1, str2;
    int i = 0, j = 0;
    FILE* fp1, * fp2;
    if ((fp1 = fopen("a.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }
    if ((fp2 = fopen("b.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }
    while ((fscanf(fp1, "%d", &str1.co[i]))!=0) {
        fscanf(fp1, "%d", &str1.ex[i]);
        i++;
    }
    while ((fscanf(fp2, "%d", &str2.co[j])) != 0) {
        fscanf(fp2, "%d", &str2.ex[j]);
        j++;
    }
    
    AddPolynomial(str1, str2);

}
