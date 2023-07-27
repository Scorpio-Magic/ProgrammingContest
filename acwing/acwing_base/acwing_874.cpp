/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: euler function
*/
#include <iostream>
using namespace std;
const int maxn = 1e6 + 7;
typedef unsigned long long ull;
int primes[maxn], phi[maxn];
bool vis[maxn];

void get_eulers(int n) {
    phi[1] = 1;
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (!vis[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        // 保证每个合数只被它的最小质因子筛掉
        for (int j = 0; primes[j] <= n / i; ++j) { 
            int number = primes[j] * i;
            vis[number] = true;
            if (i % primes[j] == 0) {
                // primes[j]是i的最小质因子, phi[i]是i的最小质因子的倍数, 所以phi[number] = phi[i] * primes[j
                phi[number] = phi[i] * primes[j]; 
                break;
            }
            // primes[j]和i互质, 所以phi[number] = phi[i] * (primes[j] - 1)
            phi[number] = phi[i] * (primes[j] - 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    get_eulers(n);
    ull res = 0;
    for (int i = 1; i <= n; ++i) res += phi[i];
    cout << res << endl;
    return 0;
}
