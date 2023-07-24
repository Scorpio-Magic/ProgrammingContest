/*
    Author: PeterAn
    Date: 2023-07-24
    Algorithm: dfs
*/
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 10;
int path[maxn];
bool vis[maxn];
int n;
void dfs(int index) {
    if (index == n) {
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            cout << path[i];
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            path[index] = i;
            dfs(index + 1);
            vis[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;;
    dfs(0);
    return 0;
}
