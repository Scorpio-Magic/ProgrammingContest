/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: factorize a number of primes
*/
#include <cstdio>

void solve(int x) {
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) {
                x /= i; ++s;
            }
            printf("%d %d\n", i, s);
        }
    }
    if (x > 1) printf("%d %d\n", x, 1);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int u; scanf("%d", &u);
        solve(u);
        printf("\n");
    }
    return 0;
}
