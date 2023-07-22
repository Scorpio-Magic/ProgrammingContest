/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: double linked list
*/
#include <iostream>
using namespace std;
const int maxn = 100000 + 10;
int l[maxn], r[maxn], val[maxn];
int idx;

void init() {
    r[0] = 1;
    l[1] = 0;
    // initialize the head and tail
    // index starts from 2, kth node is between k and k + 1
    idx = 2; 
}

void add_right(int k, int value) {
    val[idx] = value;
    r[idx] = r[k]; l[idx] = k; l[r[k]] = idx; r[k] = idx;
    idx++;
}

void remove_kth(int k) {
    r[l[k]] = r[k]; l[r[k]] = l[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    init();
    int m; cin >> m;
    for (int cases = 0; cases < m; cases++) {
        string op; cin >> op;
        if (op == "R") {
            int value; cin >> value;
            add_right(l[1], value);
        } else if (op == "L") {
            int value; cin >> value;
            add_right(0, value);
        } else if (op == "IL") {
            int k, value; cin >> k >> value;
            add_right(l[k + 1], value);
        } else if (op == "IR") {
            int k, value; cin >> k >> value;
            add_right(k + 1, value);
        } else if (op == "D") {
            int k; cin >> k;
            remove_kth(k + 1);
        }
    }

    for (int i = r[0]; i != 1; i = r[i]) {
        if (i != r[0]) cout << " ";
        cout << val[i];
    }
    cout << endl;
    return 0;
}
