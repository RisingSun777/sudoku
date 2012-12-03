#include <stdio.h>
#include "sudoku.h"

int main(void) {
    boardptr b = board_new();
    b[5][5] = 0;
    SETBIT(3, b[5][5]);
    board_print(b);
    board_delete(b);
}
