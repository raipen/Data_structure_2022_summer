#include <stdio.h>
#include <stdlib.h>

typedef enum {OPEN,CLOSE,PATH,START,FINISH} MAZE_TYPE;
typedef struct{int row,col;} coordinates;
typedef struct{
    int** data;
    coordinates size,start,end;
}matrix;
typedef int direction;
typedef struct {
    coordinates data;
    direction dir;
} element;
typedef enum {FALSE,TRUE} BOOL;
typedef struct{
    element* data;
    int top,capacity;
}stack;

matrix* readMazeFile(char* filename);
void readMazeSize_addWallSize(FILE* file,matrix* maze);
void CreateMazeWithWall(matrix* maze);
int** CreateZeroFill2DArray(int row,int col);
void fillWall(matrix* maze);
void readMazeInside(FILE* file,matrix* maze);
void readMazeStartAndEnd(FILE* file,matrix* maze);
stack* solveMaze(matrix* maze);
BOOL isEqualCoor(coordinates c1,coordinates c2);
element* nextPath(element* cur,int** maze,int** visited);
void printPath(matrix* maze, stack* path);
void printMaze(matrix* maze);
char convertMazeInfo(MAZE_TYPE type);
stack* newStack();
BOOL isFull(stack* s);
BOOL isEmpty(stack* s);
void push(stack* s,element value);
element pop(stack* s);
element peek(stack* s);