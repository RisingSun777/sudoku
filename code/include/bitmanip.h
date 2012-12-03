#define BIT(x) (1 << ((x) - 1))
#define SETBIT(b, n) (n) = ((n) | BIT(b))
#define CLEARBIT(b, n) (n) = (~BIT(b) & (n))
#define TESTBIT(b, n) (BIT(b) & (n))

int countones(int n);
