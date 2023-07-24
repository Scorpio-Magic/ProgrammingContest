/*
    Author: PeterAn
    Date: 2023-07-24
    Algorithm: bfs
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


typedef pair<int, int> PII;
int n, m;
const int maxn = 107;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int g[maxn][maxn], d[maxn][maxn];

int bfs() {
    queue<PII> que;
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    que.push({0, 0});
    while (que.size()) {
        auto loc = que.front(); que.pop();
        for (int i = 0; i < 4; ++i) {
            int x = loc.first + dx[i], y = loc.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1) {
                d[x][y] = d[loc.first][loc.second] + 1;
                que.push({x, y});
            }
        }
    }
    return d[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> g[i][j];
    }
    cout << bfs() << endl;
    return 0;
}
