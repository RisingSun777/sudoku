#include <stdio.h>
#include "sudoku.h"

int main(void) {
    boardptr b = board_new();
    board_read(b);
    //board_solve(b);
    board_print(b);
    board_delete(b);
}
