/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: trie tree
*/
/*
    数字的范围是：0~2^31，做多有30位
    做题思路：枚举集合中的两个数的异或值，再考虑优化

    root 下面紧跟的是数的第31位
        root
       /   \
      0     1
     / \   /
    0  1  0
    
*/

#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = maxn * 31;
int son[maxm][2], idx;

void insert_val(int val) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (val >> i) & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
}

int query_val(int val) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (val >> i) & 1;
        if (son[p][u ^ 1]) {
            res = (res << 1) + u ^ 1;
            p = son[p][u ^ 1];
        } else {
            res = (res << 1) + u;
            p = son[p][u];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int ans_max = -1;
    while (n--) {
        int val; cin >> val;
        insert_val(val);
        ans_max = max(ans_max, query_val(val) ^ val);
    }
    cout << ans_max << endl;
    return 0;
}
