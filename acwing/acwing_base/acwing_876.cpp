/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: quick_pow calculate inverse element
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll quick_pow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        ll a, p; cin >> a >> p;
        if (a % p == 0) {
            cout << "impossible" << endl;
            continue;
        }
        cout << quick_pow(a, p - 2, p) << endl;
    }
    return 0;
}
