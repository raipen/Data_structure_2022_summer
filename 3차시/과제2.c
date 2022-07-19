#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct{
  int col;
  int row;
  int value;
} term;

void readMatrixFromFile(term matrix[],FILE *file);
void transposeMatrix(term matrix[],term trans[]);
int* calcPosition(term matrix[]);
void printMatrix(char* prefix,term matrix[]);

int main(void){
    term matrix[MAX_TERMS],trans[MAX_TERMS];
    char filename[100];
    scanf("%s", filename);
    readMatrixFromFile(matrix,fopen(filename, "r"));
    transposeMatrix(matrix,trans);

    printMatrix("Before Transposing", matrix);
    printMatrix("\nAfter Transposing", trans);
    return 0;
}

void readMatrixFromFile(term matrix[],FILE *file){
    fscanf(file, "%d %d %d", &matrix[0].row, &matrix[0].col, &matrix[0].value);
    for(int i=1; i<=matrix[0].value; i++)
        fscanf(file, "%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
}

void transposeMatrix(term matrix[],term trans[]){
    int* startPos = calcPosition(matrix);
    trans[0].row = matrix[0].col;
    trans[0].col = matrix[0].row;
    trans[0].value = matrix[0].value;
    for(int i=1; i<=matrix[0].value; i++){
        int temp = startPos[matrix[i].col]++;
        trans[temp].row = matrix[i].col;
        trans[temp].col = matrix[i].row;
        trans[temp].value = matrix[i].value;
    }
}

int* calcPosition(term matrix[]){
    int* colCount = (int*)calloc(matrix[0].col,sizeof(int));
    for(int i=1; i<=matrix[0].value; i++)
        colCount[matrix[i].col]++;
    
    int* startPos = (int*)calloc(matrix[0].col,sizeof(int));
    startPos[0] = 1;
    for(int i=1;i<matrix[0].col; i++)
        startPos[i] = startPos[i-1] + colCount[i-1];

    return startPos;
}

void printMatrix(char* prefix,term matrix[]){
    printf("%s\n",prefix);
    int** arr2D = (int**) malloc(sizeof(int*)*matrix[0].row);
    for(int i=0;i<matrix[0].row;i++)
        arr2D[i] = (int*)malloc(sizeof(int) * matrix[0].col);
    for(int i=1;i<=matrix[0].value;i++)
        arr2D[matrix[i].row][matrix[i].col] = matrix[i].value;
    for(int i=0;i<matrix[0].row;i++){
        for(int j=0;j<matrix[0].col;j++)
            printf("%3d", arr2D[i][j]);
        printf("\n");
    }
}


