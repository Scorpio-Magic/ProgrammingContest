/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: divisors number
*/
#include <iostream>
#include <unordered_map>
using namespace std;
const int mod = 1e9 + 7;
typedef unsigned long long ULL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<int, int> hash;
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        for (int p = 2; p <= x / p; ++p) {
            while (x % p == 0) {
                x /= p;
                hash[p]++;
            }
        }
        if (x > 1) hash[x]++;
    }
    ULL ans = 1;
    for (auto it = hash.begin(); it != hash.end(); ++it) {
        ans = (ans * (it->second + 1)) % mod;
    }
    cout << ans << endl;
    return 0;
}
