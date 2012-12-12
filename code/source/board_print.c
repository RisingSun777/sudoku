#include <stdio.h>
#include "sudoku.h"
#include "helpers.h"

void board_prettyprint(boardptr b) {
    if (!b)
        return;

    for (int i = 0; i < MAXSIZE; ++i) {
        if (i % 3 == 0)
            printf("-------------------------\n");
        for (int j = 0; j < MAXSIZE; ++j) {
            if (j % 3 == 0)
                printf("| ");

            int val = cell_val(b[i][j]);

            if (val == MAXVAL + 1)
                printf(". ");
            else if (val == -1)
                printf("x ");
            else
                printf("%d ", val);

            if (j == MAXVAL - 1)
                printf("|\n");
        }
        if (i == MAXVAL - 1)
            printf("-------------------------\n");
    }
}

void board_normalprint(boardptr b) {
    if (!b)
        return;

    for (int i = 0; i < MAXSIZE; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            int val = cell_val(b[i][j]);

            if (val == MAXVAL + 1)
                printf(". ");
            else if (val == -1)
                printf("x ");
            else
                printf("%d ", val);
        }
        printf("\n");
    }
}
