/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: operation on heap, keep the index of the value
*/


#include <iostream>
using namespace std;
const int maxn = 100010;
// heap: store the value
// hp[i] = k: the index i is the k-th inserted value
// ph[k] = i: the index of k-th inserted value is i
int heap[maxn], hp[maxn], ph[maxn], heap_size;

void heap_swap(int a, int b) {
    swap(heap[a], heap[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}

void heap_down(int rt) {
    while (rt * 2 <= heap_size) {
        int now = rt * 2, rson = now + 1;
        if (rson <= heap_size && heap[rson] < heap[now]) now = rson;
        if (heap[now] < heap[rt]) heap_swap(now, rt);
        rt = now;
    }
}

void heap_up(int rt) {
    while (rt / 2 && heap[rt] < heap[rt / 2]) {
        heap_swap(rt, rt / 2);
        rt >>= 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int kth = 0;
    while (n--) {
        string op; cin >> op;
        if ("I" == op) {
            int val; cin >> val;
            ++heap_size;
            ++kth;
            heap[heap_size] = val;
            hp[heap_size] = kth;
            ph[kth] = heap_size;
            heap_up(heap_size);
        } else if ("PM" == op) {
            cout << heap[1] << '\n';
        } else if ("DM" == op) {
            heap_swap(1, heap_size);
            --heap_size;
            heap_down(1);
        } else if ("D" == op) {
            int k; cin >> k;
            int index = ph[k];
            heap_swap(index, heap_size);
            --heap_size;
            heap_down(index);
            heap_up(index);
        } else if ("C" == op) {
            int k, val; cin >> k >> val;
            int index = ph[k];
            heap[index] = val;
            heap_down(index);
            heap_up(index);
        }
    }
    return 0;
}
