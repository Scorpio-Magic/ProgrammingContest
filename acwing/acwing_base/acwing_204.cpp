/*
    Author: PeterAn
    Date: 2023-07-28
    Algorithm: 扩展中国剩余定理
*/

#include <iostream>
using namespace std;

typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (0 == b) {
        x = 1; y = 0; return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll mod(ll a, ll b) {
    return (a % b + b) % b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    ll a1, m1; cin >> a1 >> m1;
    bool solvable = true;
    for (int i = 1; i < n; ++i) {
        ll a2, m2, k1, k2; cin >> a2 >> m2;
        if (!solvable) continue;
        ll d = exgcd(a1, -a2, k1, k2);
        if ((m2 - m1) % d) {
            solvable = false;
            continue;
        }
        k1 = mod(k1 * (m2 - m1) / d, abs(a2 / d));
        m1 = k1 * a1 + m1;
        a1 = abs(a1 / d * a2);
    }
    if (solvable) cout << mod(m1, a1) << endl;
    else cout << -1 << endl;
    return 0;
}
