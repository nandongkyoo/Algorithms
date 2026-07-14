#include <stdio.h>
#include "maze.h"

int main() {
    int startRow = 0, startCol = 0;
    int endRow = 4, endCol = 4;

    if(dfs(startRow, startCol, endRow, endCol) == 1) {
        printf("미로찾기 성공!\n");
    }
    else {
        printf("미로찾기 실패\n");
    }
    return 0;
}