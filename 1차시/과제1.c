#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct score {
    char name[10];
    int a;//중간
    int b;//기말
    int c;//과제
    int av;//평균
};

void main(){
    char line[100];
    int size;
    struct score k[100];

    FILE* fp = fopen("score.txt", "r");
    FILE* fp2 = fopen("result.txt", "w");
    if (!fp) {
        printf("파일 없음");
        exit(1);
    }

    for (int i = 0; fscanf(fp, "%s %d %d %d", k[i].name, &k[i].a, &k[i].b, &k[i].c)==4; i++) {
        k[i].av = (k[i].a + k[i].b + k[i].c) / 3;
        fprintf(stdout, "%s %d\n", k[i].name, k[i].av);
        fprintf(fp2, "%s %d\n", k[i].name, k[i].av);
    }


    fclose(fp);
    fclose(fp2);
}
