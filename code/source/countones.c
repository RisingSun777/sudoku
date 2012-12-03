int countones(int n) {
    int r = 0;
    while (n) {
        n &= n - 1;
        ++r;
    }
    return r;
}
