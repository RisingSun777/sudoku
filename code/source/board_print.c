#include <stdio.h>
#include "sudoku.h"

void board_print(int (* board)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (countones(board[i][j]) == 1)
                printf("%d ", board[i][j]);
            else
                printf(". ");

            if ((j + 1) % 3 == 0 && j != 8)
                printf("| ");
        }
        printf("\b\n");
        if ((i + 1) % 3 == 0 && i != 8)
            printf("---------------------\n");
    }
}
