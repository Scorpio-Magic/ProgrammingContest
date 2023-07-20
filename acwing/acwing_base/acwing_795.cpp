/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: sum of prefix
*/

#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int num[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> num[i];
    // sum of prefix
    for (int i = 1; i < n; ++i) num[i] += num[i - 1];
    for (int cases = 0; cases < m; ++cases) {
        int l, r;
        cin >> l >> r;
        cout << num[r - 1] - num[l - 2] << endl;
    }
    return 0;
}
