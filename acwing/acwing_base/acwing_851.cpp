/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: SPFA (Shortest Path Faster Algorithm)
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 7;
int h[maxn], e[maxn], nex[maxn], w[maxn], idx;
bool vis[maxn];
int dist[maxn], que[maxn];

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
}

void add_edge(int u, int v, int val) {
    e[idx] = v; w[idx] = val; nex[idx] = h[u]; h[u] = idx++;
}

void spfa() {
    int hh = 0, tt = 0;
    que[tt++] = 1; dist[1] = 0; vis[1] = true;
    while (hh < tt) {
        int u = que[hh++];
        vis[u] = false;
        for (int i = h[u]; ~i; i = nex[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                if (!vis[v]) { // nodes in queue will be updated again
                    vis[v] = true;
                    que[tt++] = v;
                }
            }
        }
    }
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
    spfa();
    if (0x3f3f3f3f == dist[n]) cout << "impossible\n";
    else cout << dist[n] << endl;
    return 0;
}
