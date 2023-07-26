/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: color the bipartite graph
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = maxn << 1;
int h[maxn], e[maxm], nex[maxm], idx;
int color[maxn];

void  init() {
    idx = 0; 
    memset(h, -1, sizeof h);
    memset(color, 0, sizeof color);
}

void add_edge(int u, int v) {
    e[idx] = v; nex[idx] = h[u]; h[u] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;

    for (int i = h[u]; ~i; i = nex[i]) {
        int v = e[i];
        if (!color[v]) {
            if (!dfs(v, 3 - c)) return false;
        } else if (color[v] == c) return false;
    }
    return true;
}

bool solve(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i, 1)) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        add_edge(u, v); add_edge(v, u);
    }
    if (solve(n)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
