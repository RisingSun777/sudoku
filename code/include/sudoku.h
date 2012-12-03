#define BIT(x) (1 << ((x) - 1))
#define SETBIT(b, n) (n) = ((n) | BIT(b))
#define CLEARBIT(b, n) (n) = (~BIT(b) & (n))
#define TESTBIT(b, n) (BIT(b) & (n))
#define CELL_INIT 0x1FF // all are possible

#define MAXSIZE 8

typedef int (* boardptr)[9];
typedef int board[][9];

boardptr board_new(void);
void board_delete(boardptr b);

void board_print(boardptr b);

int board_issolved(boardptr b);

int cell_val(int cell);

int countones(int n);
