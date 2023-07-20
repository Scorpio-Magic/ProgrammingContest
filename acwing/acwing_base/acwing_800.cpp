/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: double pointer
*/
#include <iostream>
using namespace std;

const int maxn = 100010;
int num_a[maxn], num_b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m, x; cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) cin >> num_a[i];
    for (int i = 0; i < m; ++i) cin >> num_b[i];

    for (int st = 0, ed = m - 1; st < n; ++st) {
        while (ed >= 0 && num_a[st] + num_b[ed] > x) --ed;
        if (ed >= 0 && num_a[st] + num_b[ed] == x) {
            cout << st << " " << ed << endl;
            --ed;
        }
    }
    return 0;
}
