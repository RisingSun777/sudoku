#include "sudoku.h"
#include "bitmanip.h"
#include "helpers.h"

void board_removeconstraint(boardptr b, int row, int col, int value) {
    /* update constraint for row */
    for (int i = 0; i < MAXSIZE; ++i)
        b[row][i] = SETBIT(value, b[row][i]);

    /* update constraint for col */
    for (int i = 0; i < MAXSIZE; ++i)
        b[i][col] = SETBIT(value, b[i][col]);

    /* update constraint for sub-square */
    int minrow = 0,
        maxrow = 0,
        mincol = 0,
        maxcol = 0;
    subsquare(row, col, &minrow, &maxrow, &mincol, &maxcol);
    for (int i = minrow; i <= maxrow; ++i)
        for (int j = mincol ; j <= maxcol; ++j)
            b[i][j] = SETBIT(value, b[i][j]);
}
