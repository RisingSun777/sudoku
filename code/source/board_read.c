#include <stdio.h>
#include <ctype.h>
#include "sudoku.h"
#include "helpers.h"

void ignorespace() {
    int c;
    while(isspace(c = getchar()))
        ;
    ungetc(c, stdin);
}
 
int board_read(boardptr b) {
    if (!b)
        return -1;

    int val, c;
    for (int i = 0; i < MAXSIZE; ++i)
        for (int j = 0; j < MAXSIZE; ++j) {
            ignorespace();
            c = getchar();
            if (c <= '9' && c >= '0') {
                val = c - '0';
                //if (val <= MAXVAL && val >= 1)
                board_setcell(b, i, j, val);
            } else if (c == '.') {
                // official ignored char
            }
        }

    return 0;
}
