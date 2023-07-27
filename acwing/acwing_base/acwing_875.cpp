/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: quick pow
*/
#include <iostream>
using namespace std;
typedef long long ll;

// ll quick_pow(ll a, ll b, ll p) {
//     ll ans = 1;
//     a %= p;
//     while (b) {
//         if (b & 1) ans = ans * a % p;
//         b >>= 1;
//         a = a * a % p;
//     }
//     return ans % p;
// }

ll quick_pow(ll a, ll b, ll p) {
    a %= p;
    if (0 == b) return 1LL;
    ll res = quick_pow(a, b >> 1, p);
    if (b & 1) return res * res % p * a % p;
    else return res * res % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        ll a, b, p; cin >> a >> b >> p;
        cout << quick_pow(a, b, p) << endl;        
    }
    return 0;
}
