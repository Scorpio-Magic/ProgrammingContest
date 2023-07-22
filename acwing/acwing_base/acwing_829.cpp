/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: simulate a queue
*/
#include <iostream>
using namespace std;
const int maxn = 1e5 + 10;
int que[maxn];
int head = 0, tail = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    
    head = tail = 0;
    while (n--) {
        string op; cin >> op;
        if ("push" == op) {
            int value; cin >> value;
            que[tail++] = value;
        } else if ("pop" == op) {
            ++head;
        } else if ("query" == op) {
            cout << que[head] << endl;
        } else if ("empty" == op) {
            if (head == tail) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
