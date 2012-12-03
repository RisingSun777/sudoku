#include <stdio.h>
#include "sudoku.h"
#define MAXSIZE 9
 
void push(int* board[], int row, int col, int val) {
    board[row - 1][col - 1] = val;
}

void input(int* board[]) {
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

void output(int* board[]) {
    for(int i = 0; i < MAXSIZE; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            printf("%d", board[i][j], "\t");
        }
        printf("\n");
    }
}