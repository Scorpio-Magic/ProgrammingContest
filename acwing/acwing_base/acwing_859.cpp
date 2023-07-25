/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: kruskal algorithm on MST
*/

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
const int maxm = 200000 + 10;
const int INF = 0x3f3f3f3f;
int fa[maxn];

typedef struct Edge{
    int u, v, w;
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
} Edge;

Edge edges[maxm];

int find_fa(int x) {
    if (fa[x] != x) fa[x] = find_fa(fa[x]);
    return fa[x]; 
}

int kruskal(Edge edges[], int n, int m) {
    sort(edges, edges + m);
    for (int i = 0; i <= n; ++i) fa[i] = i;

    int weight_sum = 0, cnt = 0;
    for (int i = 0; i < m; ++i) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        int fa_u = find_fa(u), fa_v = find_fa(v);
        if (fa_u != fa_v) {
            fa[fa_u] = fa_v;
            weight_sum += w;
            ++cnt;
        }
    }
    if (cnt != n - 1) return INF;
    return weight_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, val; cin >> u >> v >> val;
        edges[i] = {u, v, val};
    }
    


    int weight_sum = kruskal(edges, n, m);
    if (weight_sum == INF) cout << "impossible\n";
    else cout << weight_sum << endl;
    return 0;
}
