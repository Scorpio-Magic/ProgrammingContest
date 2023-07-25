/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: topological sort
*/
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 10;
int h[maxn], e[maxn], ne[maxn], idx;
int que[maxn], in_d[maxn];

void init() {
    memset(h, -1, sizeof(h));
    idx = 0;
    memset(in_d, 0, sizeof(in_d));
}

int topsort(int n) {
    int head = 0, tail = 0;
    for (int i = 1; i <= n; ++i) {
        if (!in_d[i]) que[tail++] = i;
    }
    while (head < tail) {
        int u = que[head++];
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            in_d[v]--;
            if (!in_d[v]) que[tail++] = v;
        }
    }
    return tail == n;
}

void add_edge(int u, int v) {
    e[idx] = v; ne[idx] = h[u]; h[u] = idx++;
}

int main() {

    init();    
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v; scanf("%d %d", &u, &v);
        add_edge(u, v);
        in_d[v]++;
    }

    if (topsort(n)) {
        for (int i = 0; i < n; ++i)  {
            if (i) printf(" ");   
            printf("%d", que[i]);
        }
    } else {
        printf("-1\n");
    }
    return 0;
}
