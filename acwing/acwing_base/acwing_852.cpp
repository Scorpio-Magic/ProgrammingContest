/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: spfa negative cycle
*/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 2007;
const int maxm = 10007;
int h[maxn], e[maxm], nex[maxm], w[maxm], idx;
int dist[maxn], cnt[maxn], que[maxm];
bool vis[maxn];

void add_edge(int u, int v, int val) {
    e[idx] = v; w[idx] = val; nex[idx] = h[u]; h[u] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    // memset(dist, 0x3f, sizeof dist);
    memset(dist, 0, sizeof dist); // distance of every node to virtual node 0 is 0
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
}

bool spfa(int n) {
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        que.push(i);
        vis[i] = true;
    }

    while (que.size()) {
        int u = que.front(); que.pop();
        vis[u] = false;
        for (int i = h[u]; ~i; i = nex[i]) {
            int v = e[i];
            if (dist[v] > dist[u] + w[i]) {
                dist[v] = dist[u] + w[i];
                cnt[v] = cnt[u] + 1; // the number of edges in the shortest path from virtual node 0 to node v
                if (cnt[v] >= n) return true; // negative cycle
                if (!vis[v]) {
                    vis[v] = true;
                    que.push(v);
                }
            }
        }
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

    if (spfa(n)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}
