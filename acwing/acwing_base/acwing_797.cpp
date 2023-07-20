/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: difference array
*/

#include <iostream>
using namespace std;
const int maxn = 100007;
int num[maxn], diff[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> num[i];
        diff[i] = num[i] - num[i - 1];
    }

    for (int cases = 0; cases < m; ++cases) {
        int l, r, c;
        cin >> l >> r >> c;
        diff[l] += c;
        diff[r + 1] -= c;
    }

    for (int i = 1; i <= n; ++i) {
        num[i] = num[i - 1] + diff[i];
        cout << num[i] << " ";
    }
    return 0;
}
