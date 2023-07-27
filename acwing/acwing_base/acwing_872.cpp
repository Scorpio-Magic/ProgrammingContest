/*
    Author: PeterAn
    Date: 2023-07-27
    Algorithm: gcd
*/
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

// int gcd(int a, int b) {
//     return b ? gcd(b, a % b) : a;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}
