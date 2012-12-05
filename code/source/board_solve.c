#include "sudoku.h"
#include "helpers.h"
#include "bitmanip.h"

int isValid(boardptr b, int row, int col, int val) {
    if(val > 9 || val < 1) //invalid argument val
        return -1;
        
    for(int i = 0; i < MAXSIZE; i++)
        if(!TESTBIT(val, b[row][i]))
            return 0;
    
    for(int i = 0; i < MAXSIZE; i++)
        if(!TESTBIT(val, b[i][col]))
            return 0;
            
    int minrow, maxrow, mincol, maxcol;
    
    subsquare(row, col, &minrow, &maxrow, &mincol, &maxcol);
    
    for(int i = minrow; i <= maxrow; i++) {
        for(int j = mincol; j <= maxcol; j++) {
            if(!TESTBIT(val, b[i][j])
                return 0;
        }
    }
    
    return 1;
}

void mySolve(boardptr b) {
    if(!boardptr) return;
    
    for(int i = 0; i < MAXSIZE; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            if(TESTBIT(10, b[i][j])) //check whether the value is fixed
                for(int val = 1; val <= MAXVAL; val++) {
                        if(isValid(b, i, j, val)) {
                            b[i][j] = val;
                            break;
                        }
                }
        }
    }
}

void helper_solve(boardptr b, int starti, int startj) {
    if(board_issolved(b) || starti < 0)
        return;
        
    int temp = 0, val = 1;
    
    for(int i = starti; i < MAXSIZE; i++) {
        for(int j = startj; j < MAXSIZE; j++) {
            val = 1;
            do {
                if(TESTBIT(val, b[i][j])) {
                    temp = b[i][j];
                    board_setcell(b, i, j, val);
                    val = 1;
                    break;
                }
                else
                    val++;
            } while(val < 10);
        }
    }
    
    if(startj-- < 0) {
        startj = MAXSIZE - 1;
        starti--;
    }
    
    //remove constraints before moving back one cell
    board_removeconstraint();
    
    helper_solve(b, starti, startj);
}

int board_solve(boardptr b) {
    if(board_issolved(b))
        return 1;

    int temp = 0, val = 1;
    
    for(int i = 0; i < MAXSIZE; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            val = 1;
            do {
                if(TESTBIT(val, b[i][j])) {
                    temp = b[i][j];
                    board_setcell(b, i, j, val);
                    val = 1;
                    break;
                }
                else
                    val++;
            } while(val < 10);
        }
    }
    
    helper_solve(b, MAXSIZE - 1, MAXSIZE - 1);
    
    return -1;
}
