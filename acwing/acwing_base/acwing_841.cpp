/*
    Author: PeterAn
    Date: 2023-07-24
    Algorithm: string hash, scanf is faster than cin
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 7;
typedef unsigned long long ull;
const int P = 31;
char str[maxn];
ull h[maxn], p[maxn];

ull cal(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    // string  str; cin >> str;
    scanf("%s", str);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
        h[i] = h[i - 1] * P + str[i - 1];
        p[i] = p[i - 1] * P;
    }

    while (m--) {
        int l1, r1, l2, r2;
        // cin >> l1 >> r1 >> l2 >> r2;
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        if (cal(l1, r1) == cal(l2, r2)) {
            // cout << "Yes" << endl;
            printf("Yes\n");
        } else {
            // cout << "No" << endl;
            printf("No\n");
        }
    }
    return 0;
}
