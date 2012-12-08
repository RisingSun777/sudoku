#define CELL_INIT 0x1FF /* all are possible */

#define SUBSQUARESIZE 3
#define MAXSIZE (SUBSQUARESIZE * SUBSQUARESIZE)
#define MAXVAL MAXSIZE

typedef struct _cell {
    int constraints;
    int fixed;
} cell;
typedef cell (* boardptr)[MAXSIZE];
typedef cell board[][MAXSIZE];

boardptr board_new(void);
void board_delete(boardptr b);

int board_read(boardptr b);
void board_prettyprint(boardptr b);
void board_normalprint(boardptr b);

int board_solve(boardptr b);
int board_issolved(boardptr b);
