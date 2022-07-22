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

    /*
    6~18번째줄과 21~33번째 줄이 완벽하게 똑같은 구조를 가지고 있다.
    이런 경우에는 함수로 처리하는 것이 좋다.
    ex)
    int main(void){
        int* arr1 = readFromFile("in1.txt");
        int* arr2 = readFromFile("in2.txt");

        for(int i = 0; i < size1; i++)
            for(int j = 0; j < size2; j++)
                if(*(arr1+i) == *(arr2 + j))
                    printf("  %d", *(arr1+i));
                    
        free(arr1);
        free(arr2);

        return 0;
    }
    
    int* readFromFile(char* filename){
        FILE* fp;
        if ((fp = fopen(filename, "r")) == NULL){
            printf("파일이 열리지 않습니다.\n");
            exit(1);
        }
        int size;
        fscanf(fp, "%d", &size);
        int *arr = (int*) malloc(sizeof(int)*size);

        for (int i = 0; i < size; i++){
            fscanf(fp, "%d", arr + i);
        }
        fclose(fp);
        return arr;
        //여기에서 할당한 arr은 나중에 메인에서 다 쓰고 난 다음에 free 해주니까 여기에서 free 하면 안 된다!!
    }
    */

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