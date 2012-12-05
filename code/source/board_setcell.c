#include "bitmanip.h"
#include "sudoku.h"
#include "helpers.h"

void board_setcell(boardptr b, int row, int col, int value) {
    board_addconstraint(b, row, col, value);
    b[row][col].constraints = SETBIT(value, 0);
}
