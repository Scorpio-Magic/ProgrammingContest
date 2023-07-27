/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: linear congruence equation
*/
#include <iostream>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (0 == b) {
        x = 1; y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        ll a, b, m; cin >> a >> b >> m;
        ll x, y, d;
        d = exgcd(a, m, x, y);
        if (b % d) cout << "impossible" << endl;
        else {
            cout << (x * (b / d) % m + m) % m << endl;
        }
    }
    return 0;
}
