#include "sudoku.h"
#include "bitmanip.h"

int board_solve(boardptr b) {
    int temp = 0, val = 1;
    for(int i = 0; i < MAXSIZE; i++) {
        for(int j = 0; j < MAXSIZE; j++) {
            val = 1;
            do {
                if(TESTBIT(val, b[i][j]) == BIT(val)) {
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
    
    //if(!board_issolved(b))
        //back one cell and start loop again
    
    return -1;
}
