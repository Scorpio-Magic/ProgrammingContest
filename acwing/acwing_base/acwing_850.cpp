/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: dijkstra with heap, using spare graph
*/

/*
    implement of dijkstra with heap
    using redundancy of node in stl heap
*/
#include <functional>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 7;
int h[maxn], e[maxn], nex[maxn], w[maxn], idx;
int dist[maxn];
bool vis[maxn];

typedef pair<int, int> pii;

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
    memset(vis, 0, sizeof vis);
    memset(dist, 0x3f, sizeof dist);
}

void add_edge(int u, int v, int val) {
    e[idx] = v; nex[idx] = h[u]; w[idx] = val; h[u] = idx++;
}

int dijkstra(int n) {
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top(); heap.pop();
        int distance = t.first, u = t.second;
        if (vis[u]) continue; // if node is redundant, skip it
        vis[u] = true;
        for (int i = h[u]; ~i; i = nex[i]) {
            int v = e[i];
            if (dist[v] > distance + w[i]) {
                dist[v] = distance + w[i];
                heap.push({dist[v], v});
            }
        }
    }
    if (0x3f3f3f3f == dist[n]) dist[n] = -1;
    return dist[n];
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

    cout << dijkstra(n) << endl;
    return 0;
}
