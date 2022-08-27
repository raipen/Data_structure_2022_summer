#define _CRT_SECURE_NO_WARNINGS
#include "maze.h"

coordinates dir[8] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

int main(void){
    matrix* maze = readMazeFile("maze3.txt");
    printf("MAZE\n");
    printMaze(maze);
    stack* path = solveMaze(maze);
    printf(isEmpty(path)?"No path!\n":"The path is:\n");
    printPath(maze,path);
}

matrix* readMazeFile(char* filename){
    FILE* fp = fopen(filename,"r");
    matrix* maze = (matrix*) malloc(sizeof(matrix));
    readMazeSize_addWallSize(fp,maze);
    CreateMazeWithWall(maze);
    readMazeInside(fp,maze);
    readMazeStartAndEnd(fp,maze);
    return maze;
}

void readMazeSize_addWallSize(FILE* file,matrix* maze){
    fscanf(file,"%d %d",&maze->size.row,&maze->size.col);
    maze->size.row+=2; maze->size.col+=2;
}

void CreateMazeWithWall(matrix* maze){
    maze->data = CreateZeroFill2DArray(maze->size);
    fillWall(maze);
}

int** CreateZeroFill2DArray(coordinates size){
    int** temp = (int**) malloc(size.row*sizeof(int*));
    for(int i=0; i<size.row; i++)
        temp[i] = (int*) calloc(size.col,sizeof(int));
    return temp;
}

void fillWall(matrix* maze){
    for(int i=0; i<maze->size.row; i++){
        if(i==0||i==maze->size.row-1)
            for(int j=1;j<maze->size.col-1;j++)
                maze->data[i][j]= CLOSE;
        maze->data[i][0] = maze->data[i][maze->size.col-1] = CLOSE;
    }
}

void readMazeInside(FILE* file,matrix* maze){
    for(int i=1;i<maze->size.row-1;i++)
        for(int j=1;j<maze->size.col-1;j++)
            fscanf(file, "%d", &maze->data[i][j]);
}

void readMazeStartAndEnd(FILE* file,matrix* maze){
    fscanf(file,"%d %d %d %d",&maze->start.row,&maze->start.col,&maze->end.row,&maze->end.col);
    maze->start.row++,maze->start.col++,maze->end.row++,maze->end.col++;
}

stack* solveMaze(matrix* maze){
    int** visited = CreateZeroFill2DArray(maze->size);
    stack* path = newStack();
    element start = {maze->start,0};
    push(path,start);
    while(!isEmpty(path)&&!isEqualCoor(peek(path).data,maze->end)){
        element cur = pop(path);
        element* next = nextPath(&cur,maze->data,visited);
        if(next!=NULL){
            visited[next->data.row][next->data.col] = TRUE;
            push(path,cur);
            push(path,*next);
        }
    }
    return path;
}

stack* solveMaze_ppt(matrix* maze){    
    int** visited = CreateZeroFill2DArray(maze->size);
    stack* path = newStack();
    element start = {maze->start,0};
    push(path,start);
    while(!isEmpty(path)){
        element cur = pop(path);
        while(TRUE){
            element* next = nextPath(&cur,maze->data,visited);
            if(next==NULL)
                break;
            push(path,cur);
            if(isEqualCoor(next->data,maze->end))
                return path;
            visited[next->data.row][next->data.col] = TRUE;
            cur = *next;
        }
    }
    return NULL;
}

BOOL isEqualCoor(coordinates c1,coordinates c2){
    return c1.row == c2.row && c1.col == c2.col;
}

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

void printPath(matrix* maze, stack* path){
    for(int i=0; i<=path->top; i++)
        maze->data[path->data[i].data.row][path->data[i].data.col] = PATH;
    maze->data[maze->start.row][maze->start.col]=START;
    maze->data[maze->end.row][maze->end.col]=FINISH;
    printMaze(maze);
}

void printMaze(matrix* maze){
    for(int i=1; i<maze->size.row-1; i++){
        for(int j=1;j<maze->size.col-1;j++)
            printf("  %c",convertMazeInfo(maze->data[i][j]));
        printf("\n");
    }
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