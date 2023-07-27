/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: the sum of divisor
*/
/*
    if N = (p1 ^ c1) * (p2 ^ c2) * ... * (pk ^ ck)
    the number of divisor: (c1 + 1) * (c2 + 1) * ... * (ck + 1)
    the sum of divisor: (1 + p1 + p1 ^ 2 + ... + p1 ^ c1) * (1 + p2 + p2 ^ 2 + ... + p2 ^ c2) * ... * (1 + pk + pk ^ 2 + ... + pk ^ ck)
*/

#include <iostream>
#include <unordered_map>
typedef unsigned long long ull;
using namespace std;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<int, int> hash;
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        for (int p = 2; p <= x / p; ++p) {
            while (x % p == 0) {
                x /= p;
                hash[p]++;
            }
        }
        if (x > 1) hash[x]++;
    }

    ull res = 1;
    for (const auto& [k, v] : hash) {
        ull ans = 1;
        int t = v;
        while (t--) {
            ans = (ans * k + 1) % mod;
        }
        res = res * ans % mod;
    }
    cout << res << endl;
    return 0;
}
