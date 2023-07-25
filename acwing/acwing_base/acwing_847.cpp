/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: traverse graph
*/

#include <iostream>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 10;
int dis[maxn], h[maxn], e[maxn], ne[maxn], idx;
bool vis[maxn];

void add_edge(int u, int v) {
    e[idx] = v; ne[idx] = h[u]; h[u] = idx++;
}

void bfs(int u) {
    queue<int> que;
    que.push(u);
    vis[u] = true;
    dis[u] = 0;
    while (!que.empty()) {
        int t = que.front(); que.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int v = e[i];
            if (vis[v]) continue;
            vis[v] = true;
            dis[v] = dis[t] + 1;
            que.push(v);
        }
    }
}

void init() {
    memset(h, -1, sizeof(h));
    idx = 0;
    memset(vis, 0, sizeof(vis));
    memset(dis, -1, sizeof(dis));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        add_edge(a, b);
    }
    bfs(1);
    cout << dis[n] << endl;
    return 0;
}
