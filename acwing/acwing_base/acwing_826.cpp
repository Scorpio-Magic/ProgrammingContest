/*
    Author: PeterAn
    Date: 2023-07-21
    Algorithm: single linked list
*/

#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int head, idx;
int e[maxn], nex[maxn];

void add_head(int x) {
    e[idx] = x;
    nex[idx] = head;
    head = idx++;
}

void add_k(int k, int x) {
    e[idx] = x;
    nex[idx] = nex[k];
    nex[k] = idx++;
}

void remove_k(int k) {
    nex[k] = nex[nex[k]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    head = -1;
    idx = 0;

    int n; cin >> n;
    while (n--) {
        string op; cin >> op;
        if (op == "I") {
            int k, x; cin >> k >> x;
            add_k(k - 1, x);
        } else if (op == "D") {
            int k; cin >> k;
            if (k == 0) head = nex[head];
            else remove_k(k - 1);
        } else {
            int x; cin >> x;
            add_head(x);
        }
    }

    for (int i = head; i != -1; i = nex[i]) cout << e[i] << ' ';
    return 0;
}
