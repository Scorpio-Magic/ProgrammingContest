/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: Union-Find Set
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
// par[i] is the parent of i, cnt[i] is the number of nodes in the set of i
int par[maxn], cnt[maxn];

int find_par(int x) {
    if (par[x] != x) par[x] = find_par(par[x]);
    return par[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        par[i] = i; cnt[i] = 1;
    }

    while (m--) {
        string op; cin >> op;
        if ("Q1" == op) {
            int x, y; cin >> x >> y;
            if (find_par(x) == find_par(y)) cout << "Yes" << endl;
            else cout << "No" << endl;            
        } else if ("Q2" == op) {
            int x; cin >> x;
            cout << cnt[find_par(x)] << endl;

        } else if ("C" == op) {
            int x, y; cin >> x >> y;
            int fx = find_par(x), fy = find_par(y);
            // merge the set of x and the set of 
            if (fx != fy) {
                par[fx] = fy;
                cnt[fy] += cnt[fx];
            }
        }
    }
    return 0;
}
