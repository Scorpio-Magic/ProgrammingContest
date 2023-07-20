/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: difference matrix
*/
#include <iostream>
using namespace std;
const int maxn = 1007;
int num[maxn][maxn], diff[maxn][maxn];

void insert_diff(int x1, int y1, int x2, int y2, int val) {
    diff[x1][y1] += val;
    diff[x2 + 1][y1] -= val;
    diff[x1][y2 + 1] -= val;
    diff[x2 + 1][y2 + 1] += val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> num[i][j];
            diff[i][j] = num[i][j] - num[i - 1][j] - num[i][j - 1] + num[i - 1][j - 1];
        }
    }

    for (int cases = 0; cases < q; ++cases) {
        int x1, y1, x2, y2, val;
        cin >> x1 >> y1 >> x2 >> y2 >> val;
        insert_diff(x1, y1, x2, y2, val);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            num[i][j] = num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1] + diff[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << num[i][j];
            if (j != m) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
