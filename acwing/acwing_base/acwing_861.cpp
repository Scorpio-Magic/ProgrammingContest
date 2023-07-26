/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: hungary algorithm
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 507;
const int maxm = 100007;

int h[maxn], e[maxm], nex[maxm], idx;
bool vis[maxn];
int match[maxn];

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(vis, 0, sizeof vis);
    memset(match, 0, sizeof match);
}
void add_edge(int u, int v) {
    e[idx] = v; nex[idx] = h[u]; h[u] = idx++;
}

bool find(int u) {
    for (int i = h[u]; ~i; i = nex[i]) {
        int v = e[i];
        if (!vis[v]) {
            vis[v] = true;
            if (!match[v] || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();

    int n1, n2, m; cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        add_edge(u, v);
    }
    
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(vis, 0, sizeof vis);
        if (find(i)) ++res;
    }
    cout << res << endl;
    return 0;
}
