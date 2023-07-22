/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: stack implementation in array
*/

#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int stk[maxn];
int top = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    while (n--) {
        string op; cin >> op;
        if (op == "push") {
            int value; cin >> value;
            stk[++top] = value;
        } else if (op == "pop") {
            --top;
        } else if (op == "query") {
            cout << stk[top] << endl;
        } else if (op == "empty") {
            if (0 == top) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
