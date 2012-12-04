#include "sudoku.h"
#include "bitmanip.h"

void helper_solve(boardptr b, int starti, int startj) {
    if(board_issolved(b) || starti < 0)
        return;
        
    int temp = 0, val = 1;
    
    for(int i = starti; i < MAXSIZE; i++) {
        for(int j = startj; j < MAXSIZE; j++) {
            val = 1;
            do {
                if(TESTBIT(val, b[i][j])) {
                    b[i][j] = temp;
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
    
    helper_solve(b, starti, startj);
}

int board_solve(boardptr b, int starti, int startj) {
    if(board_issolved(b))
        return 1;

    int temp = 0, val = 1;
    
    for(int i = 0; i < MAXSIZE; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            val = 1;
            do {
                if(TESTBIT(val, b[i][j])) {
                    b[i][j] = temp;
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
