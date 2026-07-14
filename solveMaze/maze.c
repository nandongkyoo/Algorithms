#include <stdio.h>
#include "maze.h"

int maze[ROW][COL] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {1, 0, 0, 0, 0}
};

int visited[ROW][COL] = {0};
// 상, 하, 좌, 우 순서
int rows[4] = {0, 0, -1, 1};
int cols[4] = {-1, 1, 0, 0};

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, int r, int c)
{
    if(isFull(s) == 1) {
        printf("Stack overflow\n");
        return;
    }

    s->top++;
    visited[r][c] = 1;
    s->data[s->top].row = r;
    s->data[s->top].col = c;
}

Point pop(Stack *s)
{
    Point p = {-1, -1};

    if(isEmpty(s)) {
        printf("Stack underflow\n");
        return p;
    }
    s->top--;
    return s->data[s->top];
}

Point top(Stack *s)
{
    return s->data[s->top];
}

int isValid(int r, int c) {
    if(r >=0 && r <= ROW && c >= 0 && c <= COL) {
        if(maze[r][c] == 0 && visited[r][c] == 0) {
            return 1;
        }
    }
    return 0;
}

int dfs(int startR, int startC, int endR, int endC) {
    Stack s;
    initStack(&s);
    push(&s, startR, startC);
    

    while(!isEmpty(&s)) {
        Point curr = top(&s);
        int movedTime = 0;
        // 출구 도착
        if(curr.row == endR && curr.col == endC) {
            return 1;
        }

        for(int i = 0; i < 4; i++) {
            int nR = curr.row + rows[i];
            int nC = curr.col + cols[i];

            if(isValid(nR, nC) == 1) {
                movedTime++;
                push(&s, nR, nC);
                break;
            }
        }
        if(movedTime == 0) {
            pop(&s);
        }
    }
    return 0;
}