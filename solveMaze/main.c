#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.h"

int main() {
    srand((unsigned int)time(NULL));

    int startRow = 0, startCol = 0;
    int endRow, endCol;
    int randNum = rand() % 2;

    if(randNum == 0) {
        endCol = 4;
        endRow = rand() % 5;
    }
    else {
        endRow = 4;
        endCol = rand() % 5;
    }

    printMaze();
    printf("종료 좌표: %d, %d\n", endRow, endCol);

    if(dfs(startRow, startCol, endRow, endCol) == 1) {
        printf("미로찾기 성공!\n");
    }
    else {
        printf("미로찾기 실패\n");
    }
    return 0;
}