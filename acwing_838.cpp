/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: heap
*/
/*
    手写堆：
    1、插入一个数 O(logN)
    2、求集合当中的最小值 O(1)
    3、删除最小值 O(logN)
    *4、删除任意一个元素
    *5、修改任意一个元素
    用数组写堆，从1开始
    lson = rt * 2, rson = rt * 2 + 1
    两个基本操作：
        1、down() 往下调整（小根堆）
            一个点往下移动，从左右孩子与其三个节点中找到最小值，往下移动
        2、up() 一个结点往上移动

    1、插入一个数：插入到最后一个位置，然后从最后一个位置up()一次
        heap[++size] = x; up(size);
    2、最小值就是小根堆的第一个元素
        heap[1];
    3、删除最小值：删除头节点，将最后一个位置替换到第一个点，down()一次
        heap[1] = heap[size--]; down(1);
    4、删除任意一个元素（第k个点）
        heap[k] = heap[size--]; down(k); up(k); 两个操作只会执行一次
    5、删除任意一个元素
        heap[k] = x; down(k); up(k);
    建堆方式 O(n)：从size / 2 down到1 是个递推数列 n/4*1 + n/8*2 + n/16*3 ~ O(n)
    void down(int x) {

    }
*/

#include <iostream>
using namespace std;
const int maxn = 100010;
int heap[maxn], head_size;

void heap_down(int rt) {
    while (rt * 2 <= head_size) { // if rt has left child
        int now = rt * 2, rson = now + 1;
        if (rson <= head_size && heap[rson] < heap[now]) now = rson; // find min bewteen left and right
        if (heap[now] < heap[rt]) {
            swap(heap[now], heap[rt]);
        }
        rt = now;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    head_size = n;
    for (int i = 1; i <= n; ++i) cin >> heap[i];
    for (int i = n / 2; i; --i) {
        heap_down(i);
    }

    while (m--) {
        cout << heap[1] << " ";
        heap[1] = heap[head_size--];
        heap_down(1);
    }
    return 0;
}
