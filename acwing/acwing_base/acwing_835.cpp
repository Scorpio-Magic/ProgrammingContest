/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: trie tree
*/

#include <cstddef>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int son[maxn][26], cnt[maxn], idx;

void insert_str(const string& str) {
    int p = 0;
    for (size_t i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    ++cnt[p];
}

int query_str(const string& str) {
    int p = 0;
    for (size_t i = 0; i < str.size(); i++) {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        string op, str; cin >> op >> str;
        if ("I" == op) insert_str(str);
        else cout << query_str(str) << endl;
    }
    return 0;
}
