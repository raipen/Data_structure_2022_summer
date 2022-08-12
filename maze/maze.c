#define _CRT_SECURE_NO_WARNINGS
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

stack* newStack(){
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->top = -1;
    temp->capacity = 1;
    temp->data = (element*)malloc(sizeof(element)*temp->capacity);
    return temp;
}

BOOL isFull(stack* s){
    return (s->capacity-1 == s->top);
}

BOOL isEmpty(stack* s){
    return s->top == -1;
}

void push(stack* s,element value){
    if(isFull(s)){
        s->capacity *= 2;
        s->data = realloc(s->data, sizeof(element) * (s->capacity));
    }
    s->data[++(s->top)] = value;
}

element pop(stack* s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty: connot POP!");
        exit(1);
    }
    return s->data[(s->top)--];
}

element peek(stack* s){
    if(isEmpty(s)){
        fprintf(stderr,"stack empty: connot POP!");
        exit(1);
    }
    return s->data[(s->top)];
}

void fillWall(matrix* maze){
    for(int i=0; i<maze->size.row; i++){
        if(i==0||i==maze->size.row-1)
            for(int j=1;j<maze->size.col-1;j++)
                maze->data[i][j]= CLOSE;
        maze->data[i][0] = maze->data[i][maze->size.col-1] = CLOSE;
    }
}

int** CreateZeroFill2DArray(int row,int col){
    int** temp = (int**) malloc(row*sizeof(int*));
    for(int i=0; i<row; i++)
        temp[i] = (int*) calloc(col,sizeof(int));
    return temp;
}

void CreateMazeWithWall(matrix* maze){
    maze->data = CreateZeroFill2DArray(maze->size.row,maze->size.col);
    fillWall(maze);
}

void readMazeInside(matrix* maze,FILE* file){
    for(int i=1;i<maze->size.row-1;i++)
        for(int j=1;j<maze->size.col-1;j++)
            fscanf(file, "%d", &maze->data[i][j]);
}

matrix readMazeFile(char* filename){
    FILE* fp = fopen(filename,"r");
    matrix maze;
    fscanf(fp,"%d %d",&maze.size.row,&maze.size.col);
    maze.size.row+=2; maze.size.col+=2; //벽 사이즈 추가
    CreateMazeWithWall(&maze);
    readMazeInside(&maze,fp);
    fscanf(fp,"%d %d %d %d",&maze.start.row,&maze.start.col,&maze.end.row,&maze.end.col);
    maze.start.row++,maze.start.col++,maze.end.row++,maze.end.col++;
    return maze;
}

char convertMazeInfo(MAZE_TYPE type){
    switch(type){
        case OPEN: return '0';
        case CLOSE: return '1';
        case PATH: return 'X';
        case START: return 'S';
        case FINISH: return 'F';
    }
}

void printMaze(matrix maze){
    for(int i=1; i<maze.size.row-1; i++){
        for(int j=1;j<maze.size.col-1;j++)
            printf("  %c",convertMazeInfo(maze.data[i][j]));
        printf("\n");
    }
}

BOOL isEqualCoor(coordinates c1,coordinates c2){
    return c1.row == c2.row && c1.col == c2.col;
}


coordinates dir[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

element* nextPath(element* cur,int** maze,int** visited){
    for(;cur->dir<8;cur->dir++){
        int nextRow = cur->data.row + dir[cur->dir].row;
        int nextCol = cur->data.col + dir[cur->dir].col;
        if(!maze[nextRow][nextCol]&&!visited[nextRow][nextCol]){
            element* next = (element*) malloc(sizeof(element));
            next->data.row = nextRow;
            next->data.col = nextCol;
            next->dir = 0;
            return next;
        }
    }
    return NULL;
}

stack* solveMaze(matrix maze){
    int** visited = CreateZeroFill2DArray(maze.size.row,maze.size.col);
    stack* path = newStack();
    element start = {{maze.start.row,maze.start.col},0};
    push(path,start);
    while(!isEmpty(path)&&!isEqualCoor(peek(path).data,maze.end)){
        element cur = pop(path);
        element* next = nextPath(&cur,maze.data,visited);
        if(next!=NULL){
            visited[next->data.row][next->data.col] = TRUE;
            push(path,cur);
            push(path,*next);
        }
    }
    return path;
}

void printPath(matrix maze, stack* path){
    for(int i=0; i<=path->top; i++)
        maze.data[path->data[i].data.row][path->data[i].data.col] = PATH;
    maze.data[maze.start.row][maze.start.col]=START;
    maze.data[maze.end.row][maze.end.col]=FINISH;
    for(int i=1; i<maze.size.row-1; i++){
        for(int j=1;j<maze.size.col-1;j++)
            printf("  %c",convertMazeInfo(maze.data[i][j]));
        printf("\n");
    }
}

int main(void){
    matrix maze = readMazeFile("maze3.txt");
    printf("MAZE\n");
    printMaze(maze);
    stack* path = solveMaze(maze);
    printf(isEmpty(path)?"No path!\n":"The path is:\n");
    printPath(maze,path);
}