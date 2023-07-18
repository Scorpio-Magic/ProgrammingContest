/*
    Author: PeterAn
    Date: 2023-07-19
    Algorithm: merge sort
*/

#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 7;
int q[maxn], tmp[maxn];

// left-closed and right-opened
void merge_sort(int q[], int l, int r) {
    if (l + 1 == r) return; // one element can be seen as sorted

    int mid = (l + r) >> 1;
    merge_sort(q, l, mid); // [l, mid)
    merge_sort(q, mid, r); // [mid, r)
    int i = l, j = mid, k = i;
    while (i < mid && j < r) {
        if (q[i] <= q[j]) tmp[k++] = q[i++];
        else tmp[k++] = q[j++];
    }
    while (i < mid) tmp[k++] = q[i++];
    while (j < r) tmp[k++] = q[j++];
    for (i = l; i < r; ++i) q[i] = tmp[i];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", q + i);
    merge_sort(q, 0, n);
    for (int i = 0; i < n; ++i) printf("%d ", q[i]);
    return 0;
}
