/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: monotonic stack
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int top;
// using stack starts from 1, when stack is empty, top = 0
int stk[maxn];
int ans[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    top = 0;
    for (int i = 0; i < n; ++i) {
        int val; cin >> val;
        while (top && stk[top] >= val) --top;
        if (top) ans[i] = stk[top];
        else ans[i] = -1;
        stk[++top] = val;
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    return 0;
}
