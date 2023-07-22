/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: kmp algorithm
*/

#include <iostream>
#include <string>
using namespace std;

const int maxn = 1e5 + 7;
int nxt[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    string str, p;
    cin >> n >> p >> m >> str;
    p = " " + p;
    str = " " + str;

    nxt[1] = 0;
    for (int i = 2, j = 0; i <= n; ++i) {
        while (j && p[i] != p[j + 1]) j = nxt[j];
        if (p[i] == p[j + 1]) ++j;
        nxt[i] = j;
    }

    for (int i = 1, j = 0; i <= m; ++i) {
        while (j && str[i] != p[j + 1]) j = nxt[j];
        if (str[i] == p[j + 1]) ++j;
        if (j == n) {
            cout << i - n << " ";
            j = nxt[j];
        }
    }
    return 0;
}
