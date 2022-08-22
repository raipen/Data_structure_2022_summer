// 더하는 부분 cnt오류남. 잘못 출력됨.
#define _CRT_SECURE_NO_WARNINGS
#define MAX 500
#include <stdio.h>
#include <stdlib.h>

typedef struct polynomial {
    int co[MAX];
    int ex[MAX];
}poly;

poly str3;

void AddPolynomial(poly str1, poly str2)
{
    int i = 0, j = 0, cnt = 0;
    while (str1.co[i] != NULL || str2.co[j] != NULL) {
        if (str1.ex[i] == str2.ex[j]) {
            str3.co[cnt] = str1.co[i] + str2.co[j];
            str3.ex[cnt] = str1.ex[i];
            i++;
            j++;
            if (str3.co[cnt] == 0) {
                cnt--;
            }
        }
        else if (str1.ex[i] > str2.ex[j] || str2.ex[j]==NULL) {
            str3.co[cnt] = str1.co[i];
            str3.ex[cnt] = str1.ex[i];
            i++;
        }
        else if (str1.ex[i] < str2.ex[j] || str1.ex[i] == NULL) {
            str3.co[cnt] = str2.co[j];
            str3.ex[cnt] = str2.ex[j];
            j++;
        }
        cnt++;
    }
}

void PrintPolynomial(poly str)
{
    int i = 0;
    while (1) {
        printf("%d^%d", str.co[i], str.ex[i]);
        if (str.ex[i] != NULL)
            printf(" + ");
        else
            break;
        i++;
    }
    printf("\n");
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
    while ((fscanf(fp1, "%d", &str1.co[i]))!=EOF) {
        fscanf(fp1, "%d", &str1.ex[i]);
        i++;
    }
    fclose(fp1);
    printf("A(x):");
    PrintPolynomial(str1);

    if ((fp2 = fopen("b.txt", "r")) == NULL) {
        printf("Error");
        return 0;
    }    
    while ((fscanf(fp2, "%d", &str2.co[j]))!=EOF) {
        fscanf(fp2, "%d", &str2.ex[j]);
        j++;
    }
    fclose(fp2);
    printf("B(x):");
    PrintPolynomial(str2);

    AddPolynomial(str1, str2);
    printf("\nC(x):");
    PrintPolynomial(str3);
}
