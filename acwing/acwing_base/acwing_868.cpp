/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: find prime numbers in [1, n]
*/

#include <cstdio>
const int maxn = 1e6 + 7;
int primes[maxn], cnt;
bool not_prime[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 2; i <= n; ++i) {
        if (!not_prime[i]) primes[cnt++] = i;
        // if i is prime, then j will stop at i
        // else i is not prime, then j will stop at i's prime factor
        // so we not need to check j's range
        for (int j = 0; primes[j] <= n / i; ++j) {
            not_prime[primes[j] * i] = true;
            // if primes[j] is i's prime factor, then primes[j] * i is not prime
            if (i % primes[j] == 0) break;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
