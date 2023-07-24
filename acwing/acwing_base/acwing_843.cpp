/*
    Author: PeterAn
    Date: 2023-07-24
    Algorithm: n-queens question
*/
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 10;

char maze[maxn][maxn];
bool cor[maxn], dg[maxn << 1], udg[maxn << 1];
int n;

void dfs(int rol) {
    if (rol == n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << maze[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (!cor[col] && !dg[rol + col] && !udg[n - rol + col]) {
            cor[col] = dg[rol + col] = udg[n - rol + col] = true;
            maze[rol][col] = 'Q';
            dfs(rol + 1);
            maze[rol][col] = '.';
            cor[col] = dg[rol + col] = udg[n - rol + col] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(cor, 0, sizeof(cor));
    memset(dg, 0, sizeof(dg));
    memset(udg, 0, sizeof(udg));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) maze[i][j] = '.';
    }
    dfs(0);
    return 0;
}
