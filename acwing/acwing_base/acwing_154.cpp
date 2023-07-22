/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: sliding window monotonic queue
*/
#include <iostream>
using namespace std;
const int maxn = 1e6 + 10;
int head, tail;
// queue save index of num array
int que[maxn], num[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> num[i];

    head = tail = 0;
    for (int i = 0; i < n; ++i) {
        if (head < tail && i - que[head] + 1 > k) ++head;
        while (head < tail && num[que[tail - 1]] >= num[i]) --tail;
        que[tail++] = i;
        if (i >= k - 1) {
            cout << num[que[head]] << ' ';
        }
    }
    cout << endl;

    head = tail = 0;
    for (int i = 0; i < n; ++i) {
        if (head < tail && i - que[head] + 1 > k) ++head;
        while (head < tail && num[que[tail - 1]] <= num[i]) --tail;
        que[tail++] = i;
        if (i >= k - 1) {
            cout << num[que[head]] << ' ';
        }
    }
    cout << endl;
    return 0;
}
