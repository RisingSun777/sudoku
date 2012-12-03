#include <stdlib.h>
#include "sudoku.h"

int (* mkboard(void))[9] {
    return calloc(1, 9 * 9 * sizeof(int));
}

void delboard(int (* board)[9]) {
    free(board);
}
