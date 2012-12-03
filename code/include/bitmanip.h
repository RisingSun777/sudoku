#define BIT(x) (1 << ((x) - 1))
#define SETBIT(b, n) ((n) | BIT(b))
#define CLEARBIT(b, n) ((n) & ~BIT(b))
#define TESTBIT(b, n) ((n) & BIT(b))

int countones(int n);
