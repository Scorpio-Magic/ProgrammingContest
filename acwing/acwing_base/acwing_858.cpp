/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: prim algorithm on MST
*/
#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 507;
int g[maxn][maxn], dist[maxn];
bool vis[maxn];

int prime(int n) {
    memset(vis, 0, sizeof vis);
    int weight_sum = 0;
    // need add n times
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
        if (i && dist[u] == INF) return INF;
        if (i) weight_sum += dist[u];
        vis[u] = true;
        // add weight first, then update dist
        for (int v = 1; v <= n; ++v) dist[v] = min(dist[v], g[u][v]);
    }
    return weight_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(g, INF, sizeof g);
    memset(dist, 0x3f, sizeof dist);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        g[v][u] = g[u][v] = min(g[u][v], w);
    }

    int ans = prime(n);
    if (INF == ans) cout << "impossible\n";
    else cout << ans << endl;

    return 0;
}
