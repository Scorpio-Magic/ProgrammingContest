/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: dijkstra matrix implement
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 507;
int g[maxn][maxn];
bool vis[maxn];
int dist[maxn];

void init() {
    memset(g, 0x3f, sizeof g);
}

int dijkstra(int n) {
    memset(dist, 0x3f, sizeof dist);
    memset(vis, 0, sizeof vis);
    dist[1] = 0;
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
        vis[u] = true;
        for (int j = 1; j <= n; ++j) {
            dist[j] = min(dist[u] + g[u][j], dist[j]);
        }
    }
    if (0x3f3f3f3f == dist[n]) dist[n] = -1;
    return dist[n]; 
}

int main() {

    init();
    int n, m;
    scanf("%d %d", &n, &m);

    while (m--) {
        int u, v, val; scanf("%d %d %d", &u, &v, &val);
        g[u][v] = min(g[u][v], val);
    }

    printf("%d\n", dijkstra(n));
    return 0;
}
