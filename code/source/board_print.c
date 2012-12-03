#include <stdio.h>
#include "sudoku.h"
#include "helpers.h"

void board_print(boardptr b) {
    if (!b)
        return;

    for (int i = 0; i < MAXSIZE; ++i) {
        for (int j = 0; j < MAXSIZE; ++j) {
            if (cell_val(b[i][j]) == 10)
                printf(". ");
            else
                printf("%d ", cell_val(b[i][j]));

            if ((j + 1) % 3 == 0 && j != MAXSIZE - 1)
                printf("| ");
        }
        printf("\b\n");
        if ((i + 1) % 3 == 0 && i != MAXSIZE - 1)
            printf("---------------------\n");
    }
}
