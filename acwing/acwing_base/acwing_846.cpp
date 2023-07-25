/*
    Author: PeterAn
    Date: 2023-07-25
    Algorithm: dfs + tree
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = maxn << 1;

int h[maxn], idx;
int e[maxm], ne[maxm];
int n, ans = 0x3f3f3f3f;
bool vis[maxn];
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u) {
    int res = 0;
    vis[u] = true;
    int sum = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (vis[v]) continue;
        int sub_cnt = dfs(v);
        res = max(res, sub_cnt);
        sum += sub_cnt;
    }

    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(vis, 0, sizeof(vis));
    memset(h, -1, sizeof(h));
    idx = 0;

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        add(a, b); add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
