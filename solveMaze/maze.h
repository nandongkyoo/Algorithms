#ifndef MAZE_H
#define MAZE_H

#define ROW 5
#define COL 5
#define MAX_SIZE (ROW * COL)

// 좌표 구조체
typedef struct 
{
    int row;
    int col;
} Point;

// 스택 구조체
typedef struct  
{
    Point data[MAX_SIZE];
    int top;
} Stack;

extern int maze[ROW][COL];
extern int visited[ROW][COL];
extern int rows[4];
extern int cols[4];

void printMaze();
void initStack(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);
void push(Stack* s, int x, int y);
Point pop(Stack* s);
Point top(Stack* s);

int isValid(int r, int c);
int dfs(int startR, int startC, int endR, int endC);

#endif