#include "bitmanip.h"
#include "sudoku.h"

int cell_val(int cell) {
    int ones = countones(cell);
    if (ones > 1)
        return 10;
    else if (ones == 0)
        return 0;

    for (int i = 1; i <= MAXVAL; ++i)
        if (TESTBIT(i, cell))
            return i;

    // can't reach this
    return -1;
}
