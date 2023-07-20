/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: double pointers
*/

#include <iostream>
using namespace std;

const int maxn = 100010;
int num_a[maxn], num_b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n; cin >> m;
    for (int i = 0; i < n; ++i) cin >> num_a[i];
    for (int i = 0; i < m; ++i) cin >> num_b[i];

    int ptr_a, ptr_b;
    for (ptr_b = 0, ptr_a = 0; ptr_b < m; ++ptr_b) {
        if (num_b[ptr_b] == num_a[ptr_a] && ptr_a < n) ++ptr_a;
    }
    if (ptr_a == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
