#define BIT(x) (1 << ((x) - 1))
#define SETBIT(b, n) (n) = ((n) | BIT(b))
#define CLEARBIT(b, n) (n) = (~BIT(b) & (n))
#define CELL_INIT 0x1FF // all are possible

int (* board_new(void))[9];
void board_delete(int (* board)[9]);

int countones(int n);
void board_print(int (* board)[9]);
