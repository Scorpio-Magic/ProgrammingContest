/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: sum of prefix in matrix
*/

#include <iostream>
using namespace std;
const int maxn = 1007;
int num[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    // sum of prefix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x; cin >> x;
            // make sum of prefix in matrix
            num[i][j] = num[i][j - 1] + num[i - 1][j] - num[i - 1][j - 1] + x;
        }
    }

    int x1, x2, y1, y2;
    for (int cases = 0; cases < q; cases++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}
