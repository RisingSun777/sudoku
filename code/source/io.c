#include <stdio.h>
#include "sudoku.h"
#define MAXSIZE 9
 
void push(boardptr board, int row, int col, int val) {
    int v = 0;
    SETBIT(val, v);
    board[row - 1][col - 1] = v;
}

void input(boardptr board) {
    int isover = 0;
    int col, row, val;
    
    while(!isover) {
        printf("Enter row position: ");
        scanf("%d", &row);
        printf("Enter column position: ");
        scanf("%d", &col);
        printf("Enter value at row %d column %d: ", row, col);
        scanf("%d", &val);
        
        push(board, row, col, val);
    
        printf("Continue adding (y/n)?");
        if(getchar() == 'y')
            isover = 1;
    }
}