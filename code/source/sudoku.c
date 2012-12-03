#include <stdio.h>
#include "sudoku.h"

int main(void) {
    int (* board)[9] = board_new();
    board_print(board);
    board_delete(board);
}
