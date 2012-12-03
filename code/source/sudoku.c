#include <stdio.h>
#include "sudoku.h"
#include "bitmanip.h"

int main(void) {
    boardptr b = board_new();

    board_read(b);
    //board_solve(b);
    board_print(b);
    printf("%d\n", board_issolved(b));

    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j)
            b[i][j] = BIT(j + 1);
    board_print(b);
    printf("%d\n", board_issolved(b));

    board_delete(b);
}
