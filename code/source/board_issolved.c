#include "sudoku.h"
#include "helpers.h"
#include "bitmanip.h"

#include <stdio.h>

int board_issolved(boardptr b) {
    if (!b)
        return 0;

    /* check for single value cells */
    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j)
            if (countones(b[i][j].constraints) != 1)
                return 0;

    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j) {
            int val = b[i][j].constraints;
            /* check col */
            for (int k = 0; k < MAXSIZE; ++k)
                if (k != j && val == b[i][k].constraints)
                    return 0;
            /* check row */
            for (int k = 0; k < MAXSIZE; ++k)
                if (k != i && val == b[k][j].constraints)
                    return 0;
            /* check subsquare */
            int minrow,
                maxrow,
                mincol,
                maxcol;
            subsquare(i, j, &minrow, &maxrow, &mincol, &maxcol);
            for (int k = minrow; k <= maxrow; ++k)
                for (int l = mincol; l <= maxcol; ++l)
                    if (i != k && j != l && val == b[k][l].constraints)
                        return 0;
        }

    /* jumped all the hoops, return success */
    return 1;
}
