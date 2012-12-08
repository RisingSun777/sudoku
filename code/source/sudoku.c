#include <stdio.h>
#include "sudoku.h"
#include "bitmanip.h"

int main(int argc, char* argv[]) {
    void (*board_print)(boardptr) = board_normalprint;
    boardptr b = board_new();

    /* parse command line */
    while (--argc > 0 && (*++argv)[0] == '-') {
        char c = *++argv[0];
        if (c == 'p')
            board_print = board_prettyprint;
        else
            board_print = board_normalprint;
    }
    
    if (board_read(b) == 0) {
        board_solve(b);
        board_print(b);
        printf("%d\n", board_issolved(b));
    }

    board_delete(b);
}
