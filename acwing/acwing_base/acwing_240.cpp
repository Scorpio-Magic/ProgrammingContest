/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: Union-Find Set with weight
*/
// using weight between node and root to judge relationship
// distance between node and root is one: eat root node
// distance between node and root is two: be eaten by root node
// distance between node and root is zero: same species
/*
                depth[fx](need to be updated)
        fa[x] ------------> fa[y](root)
           |                   |    
           |depth[x]           |depth[y]
           |                   |
           x                   y
*/
#include <iostream>
using namespace std;
const int maxn = 500000 + 10;
int fa[maxn], depth[maxn];

int find_fa(int x) {
    if (fa[x] != x) {
        int tmp = find_fa(fa[x]);
        depth[x] += depth[fa[x]];
        fa[x] = tmp;
    }
    return fa[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        fa[i] = i;
        depth[i] = 0;
    }
    int cnt_fake = 0;
    while (k--) {
        int op, x, y; cin >> op >> x >> y;
        if (x > n || y > n) {
            cnt_fake++;
            continue;
        }
        int fx = find_fa(x), fy = find_fa(y);
        if (1 == op) {
            // judge legal X and Y are in the same set
            if (fx == fy && (((depth[x] - depth[y] % 3) + 3) % 3)) {
                cnt_fake++;
            } else if (fx != fy) { // merge new set
                fa[fx] = fy;
                depth[fx] = depth[y] - depth[x];
            }
        } else { // 2 == op, X eats Y
            if (fx == fy && (((depth[x] - depth[y] % 3) + 2) % 3)) {
                cnt_fake++;
            } else if (fx != fy) {
                fa[fx] = fy;
                depth[fx] = (depth[y] - depth[x] + 1);
            }
        }

    }
    cout << cnt_fake << endl;
    return 0;
}
