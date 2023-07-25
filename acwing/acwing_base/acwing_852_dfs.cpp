/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: dfs negative cycle
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2007;
const int maxm = 10007;
int h[maxn], e[maxm], nex[maxm], w[maxm], idx;
int dist[maxn];
int vis[maxn];

void add_edge(int u, int v, int val) {
    e[idx] = v; w[idx] = val; nex[idx] = h[u]; h[u] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    // memset(dist, 0x3f, sizeof dist);
    memset(dist, 0, sizeof dist); // distance of every node to virtual node 0 is 0
    memset(vis, 0, sizeof vis);
}

bool dfs(int u) {
    vis[u] = 1;
    for (int i = h[u]; ~i; i = nex[i]) {
        int v = e[i];
        if (dist[v] > dist[u] + w[i]) {
            dist[v] = dist[u] + w[i];
            if (vis[v] == 1) return true;
            if (dfs(v)) return true;
        }
    }
    vis[u] = 2;
    return false;
}

bool check_negative_cycle(int n) {
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (dfs(i)) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, val; cin >> u >> v >> val;
        add_edge(u, v, val);
    }

    if (check_negative_cycle(n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
