#include <stdlib.h>
#include "sudoku.h"

boardptr board_new(void) {
    int (* board)[9] = calloc(1, 9 * 9 * sizeof(int));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = CELL_INIT;
    return board;
}

void board_delete(boardptr b) {
    free(b);
}
