#include <stdio.h>
#include "sudoku.h"
#include "helpers.h"

void board_print(boardptr b) {
    if (!b)
        return;

    for (int i = 0; i < MAXSIZE; ++i) {
        if (i % 3 == 0)
            printf("-------------------------\n");
        for (int j = 0; j < MAXSIZE; ++j) {
            if (j % 3 == 0)
                printf("| ");

            if (cell_val(b[i][j]) == 10)
                printf(". ");
            else
                printf("%d ", cell_val(b[i][j]));

            if (j == MAXVAL - 1)
                printf("|\n");
        }
        if (i == MAXVAL - 1)
            printf("-------------------------\n");
    }
}
