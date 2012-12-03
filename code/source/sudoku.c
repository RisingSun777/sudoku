#include <stdio.h>
#include "sudoku.h"

int main(void) {
    int (* board)[9] = board_new();
    board[5][5] = 0;
    SETBIT(3, board[5][5]);
    board_print(board);
    board_delete(board);
}
