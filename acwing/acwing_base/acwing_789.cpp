/*
    Author: PeterAn
    Date: 2023-07-19
    Algorithm: binary search || two pointers || left closed right open
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 7;
int q[maxn];

int main() {
    int n, ques; scanf("%d %d", &n, &ques);
    for (int i = 0; i < n; ++i) scanf("%d", q + i);
    for (int i = 0; i < ques; ++i) {
        int k; scanf("%d", &k);
        // long st = lower_bound(q, q + n, k) - q;
        // long ed = upper_bound(q, q + n, k) - q;
        int l = 0, r = n, st = 0, ed = 0;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] >= k) r = mid;
            else l = mid + 1;
        }
        st = r;

        l = 0, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (q[mid] > k) r = mid;
            else l = mid + 1;
        }
        ed = r;

        if (st >= ed) printf("-1 -1\n");
        else printf("%d %d\n", st, ed - 1);

    }
    return 0;
}
