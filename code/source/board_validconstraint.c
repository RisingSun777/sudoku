#include "sudoku.h"
#include "helpers.h"

int board_validconstraint(boardptr b, int row, int col) {
    for (int i = 0; i < MAXSIZE; ++i)
        if (!b[i][col])
            return 0;

    for (int i = 0; i < MAXSIZE; ++i)
        if (!b[row][i])
            return 0;

    int minrow, maxrow, mincol, maxcol;
    subsquare(row, col, &minrow, &maxrow, &mincol, &maxcol);
    for (int i = minrow; i <= maxrow; ++i)
        for (int j = mincol; j <= maxcol; ++j)
            if (!b[i][j])
                return 0;

    return 1;
}
