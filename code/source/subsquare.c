#include "sudoku.h"

int subsquare(int row, int col,
              int* minrow, int* maxrow,
              int* mincol, int* maxcol) {
    if (!minrow || !maxrow || !mincol || !maxcol)
        return -1;

    *minrow = (row / SUBSQUARESIZE) * SUBSQUARESIZE;
    *maxrow = *minrow + SUBSQUARESIZE - 1;
    *mincol = (col / SUBSQUARESIZE) * SUBSQUARESIZE;
    *maxcol = *mincol + SUBSQUARESIZE - 1;

    return 0;
}
