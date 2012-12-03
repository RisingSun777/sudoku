#include <stdio.h>
#include "sudoku.h"

void board_print(boardptr b) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (cell_val(b[i][j]) == 10)
                printf(". ");
            else
                printf("%d ", cell_val(b[i][j]));

            if ((j + 1) % 3 == 0 && j != 8)
                printf("| ");
        }
        printf("\b\n");
        if ((i + 1) % 3 == 0 && i != 8)
            printf("---------------------\n");
    }
}
