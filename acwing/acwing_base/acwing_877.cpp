/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: extended gcd
*/
#include <iostream>

using namespace std;
typedef long long ll;

ll ex_gcd(ll a, ll b, ll &x, ll &y) {
    if (0 == b) {
        x = 1; y = 0;
        return a;
    }
    ll d = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        ll a, b; cin >> a >> b;
        ll x, y;
        ex_gcd(a, b, x, y);
        cout << x << " " << y << endl;
    }
    return 0;
}
