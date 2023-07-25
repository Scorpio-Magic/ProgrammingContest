/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: floyd algorithm
*/

// dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])
// dist[k][i][j]: from i to j, the shortest path with k nodes

#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 207;
int dist[maxn][maxn];

void floyd(int n) {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, q; cin >> n >> m >> q;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i <= n; ++i) dist[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, val; cin >> u >> v >> val;
        dist[u][v] = min(dist[u][v], val);
    }

    floyd(n);

    for (int i = 0; i < q; ++i) {
        int u, v; cin >> u >> v;
        if (dist[u][v] > INF / 2) cout << "impossible" << endl;
        else cout << dist[u][v] << endl;
    }
    return 0;
}
