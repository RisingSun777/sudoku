#include <stdio.h>
#include "sudoku.h"
#include "helpers.h"
 
int board_read(boardptr b) {
    if (!b)
        return -1;

    int val = 0;
    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j) {
            scanf("%d", &val);
            if (val <= MAXVAL && val >= 1)
                board_setcell(b, i, j, val);
        }

    return 0;
}
