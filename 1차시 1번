#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[50];
    int s1;
    int s2;
    int s3;
    int ave;
}stu;

void main()
{
    int i=0;
    stu data[5];
    FILE* fp;
    FILE* fp1;
    fp = fopen("score.txt", "r");
    fp1 = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("ERROR");
        return 0;
    }

    while (fscanf(fp, "%s %d %d %d",
        data[i].name, &data[i].s1, &data[i].s2, &data[i].s3) != EOF) {
        data[i].ave = (data[i].s1 + data[i].s2 + data[i].s3) / 3;
        fprintf(fp, "%s %d\n", data[i].name, data[i].ave);
        printf("%s %d\n", data[i].name, data[i].ave);
        i++;
    }   
    fclose(fp);
    fclose(fp1); 
}
