#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* f1;
    if ((f1 = fopen("in1.txt", "r")) == NULL){
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    int size1;
    fscanf(f1, "%d", &size1);
    int *arr1 = (int*) malloc(sizeof(int)*size1);

    for (int i = 0; i < size1; i++){
        fscanf(f1, "%d", arr1 + i);
    }
    fclose(f1);


    FILE* f2;
    if ((f2 = fopen("in2.txt", "r")) == NULL){
        printf("파일이 열리지 않습니다.\n");
        exit(1);
    }
    int size2;
    fscanf(f2, "%d", &size2);
    int *arr2 = (int*) malloc(sizeof(int)*size2);

    for (int j = 0; j < size2; j++){
        fscanf(f2, "%d", arr2 + j);
    }
    fclose(f2);

    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size2; j++){
            if(*(arr1+i) == *(arr2 + j)){
                printf("  %d", *(arr1+i));
            }
        }
    }

    free(arr1);
    free(arr2);

    return 0;
}