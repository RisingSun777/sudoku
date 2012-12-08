#include "sudoku.h"
#include "helpers.h"
#include "bitmanip.h"

int isValid(boardptr b, int row, int col, int val) {
    //check the column if matched
    for(int i = 0; i < MAXSIZE; i++) {
        if(val == cell_val(b[row][i].constraints))
            return 0;
    }
    
    //check the row if matched
    for(int i = 0; i < MAXSIZE; i++) {
        if(val == cell_val(b[i][col].constraints))
            return 0;
    }
            
    int minrow, maxrow, mincol, maxcol;
    
    subsquare(row, col, &minrow, &maxrow, &mincol, &maxcol);
    
    //check the subsquare if matched
    for(int i = minrow; i <= maxrow; i++)
        for(int j = mincol; j <= maxcol; j++)
            if(val == cell_val(b[i][j].constraints))
                return 0;
    
    return 1;
}

void moveBackAndIncrement(boardptr b, int row, int col) {
    if(row < 0 || col < 0)
        return;
        
    if(col > 0) {
        if(b[row][col - 1].fixed) {
            moveBackAndIncrement(b, row, col - 1);
            return;
        }
        for(int val = cell_val(b[row][col - 1].constraints); val <= MAXVAL; val++) {
            if(isValid(b, row, col - 1, val)) {
                b[row][col - 1].constraints = BIT(val);
                return;
            }
            if(val == MAXVAL) {
                b[row][col - 1].constraints = CELL_INIT;
                moveBackAndIncrement(b, row, col - 1);
            }
        }
    }
    else {
        if(b[row - 1][MAXSIZE - 1].fixed) {
            moveBackAndIncrement(b, row - 1, MAXSIZE - 1);
            return;
        }
        for(int val = cell_val(b[row - 1][MAXSIZE - 1].constraints); val <= MAXVAL; val++) {
            if(isValid(b, row - 1, MAXSIZE - 1, val)) {
                b[row - 1][MAXSIZE - 1].constraints = BIT(val);
                return;
            }
            if(val == MAXVAL) {
                b[row - 1][MAXSIZE - 1].constraints = CELL_INIT;
                moveBackAndIncrement(b, row - 1, MAXSIZE - 1);
            }
        }
    }
}

int board_solve(boardptr b) {
    if(!b)
        return 0;
        
    if(board_issolved(b))
        return 1;
    
    for(int i = 0; i < MAXSIZE; i++)
        for(int j = 0; j < MAXSIZE; j++) {
            if(countones(b[i][j].constraints) != 1) {
                if(b[i][j].constraints == 0) {
                    b[i][j].constraints = CELL_INIT;
                    board_solve(b);
                }
                    
                for(int val = 1; val <= MAXSIZE; val++) {
                    if(isValid(b, i, j, val)) {
                        b[i][j].constraints = BIT(val);
                        break;
                    }
                    if(val == MAXVAL) {
                        moveBackAndIncrement(b, i, j);
                        board_solve(b);
                    }
                }
            }
        }
        
    return 1;
}