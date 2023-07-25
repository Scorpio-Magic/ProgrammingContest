/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: bellman-ford algorithm
*/

#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 507;
const int maxm = 1e4 + 7;

struct Edge {
    int u, v, val;
} edge[maxm];

int dist[maxn], backup[maxn];
int n, m, k;

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; ++i) { // find shortest path with at most k edges
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; ++j) { // bellman-ford algorithm need traverse all edges
            auto e = edge[j];
            dist[e.v] = min(dist[e.v], backup[e.u] + e.val);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < m; ++i) {
        int u, v, val; cin >> u >> v >> val;
        edge[i] = {u, v, val};
    }

    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2) { // 0x3f3f3f3f / 2 is a big enough number
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}
