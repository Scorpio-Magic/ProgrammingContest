/*
    Author: PeterAn
    Date: 2023-07-26
    Algorithm: test prime
*/
#include <iostream>
#include <cstring>
using namespace std;

bool check_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int u; cin >> u;
        if (check_prime(u)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
