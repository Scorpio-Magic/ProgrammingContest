/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: calculate the divisors of n
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    for (int cases = 1; cases <= T; cases++) {
        int n; cin >> n;
        vector<int> res;
        for (int i = 1; i <= n / i; ++i) {
            if (n % i == 0) {
                res.push_back(i);
                if (i != n / i) res.push_back(n / i);
            }
        }
        sort(res.begin(), res.end());
        for (auto x = res.begin(); x != res.end(); ++x) {
            if (x != res.begin()) cout << " ";
            cout << *x;
        }
        cout << endl;
    }
    return 0;
}
