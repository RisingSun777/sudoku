#include <stdlib.h>
#include "sudoku.h"

int (* board_new(void))[9] {
    int (* board)[9] = calloc(1, 9 * 9 * sizeof(int));
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            board[i][j] = CELL_INIT;
    return board;
}

void board_delete(int (* board)[9]) {
    free(board);
}
