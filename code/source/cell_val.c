#include "sudoku.h"

int cell_val(int cell) {
    for (int i = 1; i <= 9; ++i)
        if (TESTBIT(i, cell))
            return i;

    // can't reach this
    return -1;
}
