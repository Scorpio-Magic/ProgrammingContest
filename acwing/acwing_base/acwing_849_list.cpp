/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: dijkstra algorithm
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 507;
const int maxm = 100007;
int h[maxn], e[maxm], ne[maxm], w[maxm], idx;
int dist[maxn];
bool vis[maxn];

void add_edge(int u, int v, int val) {
    e[idx] = v; ne[idx] = h[u]; w[idx] = val; h[u] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
}

void dijkstra(int st, int n) {
    dist[st] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (u == -1 || dist[u] > dist[j])) u = j;
        }
        vis[u] = true;
        for (int j = h[u]; ~j; j = ne[j]) {
            int v = e[j];
            // if (dist[v] > dist[u] + w[i]) dist[v] = dist[u] + w[i];
            dist[v] = min(dist[v], dist[u] + w[j]);
        }
    }
    if (dist[n] == 0x3f3f3f3f) dist[n] = -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();

    int n, m; cin >> n >> m;
    for (int cases = 0; cases < m; ++cases) {
        int u, v, val; cin >> u >> v >> val;
        add_edge(u, v, val);
    }
    dijkstra(1, n);
    cout << dist[n] << endl;
    return 0;
}
