/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: discretization, sort, greedy
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;
vector<PII> segs;

void merge_segments(vector<PII> &segs) {
    vector<PII> res;
    sort(segs.begin(), segs.end());
    int st = -2e9, ed = -2e9;
    for (auto seg: segs) {
        if (ed < seg.first) { // no intersection
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        } else { // has intersection, update ed
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9) res.push_back({st, ed});
    segs = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        segs.push_back({l, r});
    }
    merge_segments(segs);
    cout << segs.size() << endl;
    return 0;
}
