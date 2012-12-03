#include <stdlib.h>
#include "sudoku.h"

boardptr board_new(void) {
    boardptr b = calloc(1, MAXSIZE * MAXSIZE * sizeof(int));
    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j)
            b[i][j] = CELL_INIT;
    return b;
}

void board_delete(boardptr b) {
    free(b);
}
