/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: lowbit calculation
*/

#include <iostream>
using namespace std;

int count_one(int x) {
    int res = 0;
    while (x) {
        x = x & (x - 1);
        // x -= x & -x; // count lowbit
        ++res;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cout << count_one(x);
        if (i != n - 1) cout << " ";
        else cout << endl;
    }
    return 0;
}
