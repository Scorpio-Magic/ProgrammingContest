/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: calculate euler function
*/
#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        ull res = x;
        for (int p = 2; p <= x / p; ++p) {
            if (0 == x % p) {
                while (0 == x % p) x /= p;
                res = res / p * (p - 1);
            }
        }
        if (x > 1) res = res / x * (x - 1);
        cout << res << endl;
    }
    return 0;
}
