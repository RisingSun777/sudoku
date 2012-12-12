#include "bitmanip.h"
#include "sudoku.h"

int cell_val(cell c) {
    int ones = countones(c.constraints);
    if (ones > 1)
        return MAXVAL + 1;
    else if (ones == 0)
        return 0;

    for (int i = 1; i <= MAXVAL; ++i)
        if (TESTBIT(i, c.constraints))
            return i;

    /* can't reach this */
    return -1;
}
