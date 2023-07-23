/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: Union-Find Set
*/

#include <iostream>
#include <string>
using namespace std;
const int maxn = 1e5 + 10;
int par[maxn];

int find_par(int x) {
    if (par[x] != x) par[x] = find_par(par[x]);
    return par[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) par[i] = i;
    while (m--) {
        string op; cin >> op;
        if ("M" == op) {
            int x, y; cin >> x >> y;
            par[find_par(x)] = find_par(y);
        } else if ("Q" == op) {
            int x, y; cin >> x >> y;
            if (find_par(x) == find_par(y)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}
