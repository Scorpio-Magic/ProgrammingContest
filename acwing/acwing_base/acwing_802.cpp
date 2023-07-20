/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: discrete, prefix sum
*/

#include <cstddef>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
vector<int> loc;
vector<PII> add, query;

int find_index(int x_index) {
    return lower_bound(loc.begin(), loc.end(), x_index) - loc.begin() + 1; // 1-baseds
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x_index, val; cin >> x_index >> val;
        add.push_back({x_index, val});
        loc.push_back(x_index);
    }
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        query.push_back({l, r});
        loc.push_back(l);
        loc.push_back(r);
    }

    sort(loc.begin(), loc.end());
    loc.erase(unique(loc.begin(), loc.end()), loc.end());
    
    vector<int> num(loc.size() + 1, 0);
    vector<int> prefix(loc.size() + 1, 0);
    for (auto& [x_index, val] : add) {
        int index = find_index(x_index);
        num[index] += val;
    }
    for (std::size_t i = 1; i <= loc.size(); ++i) {
        prefix[i] = prefix[i - 1] + num[i];
    }
    for (auto& [l, r] : query) {
        int l_index = find_index(l);
        int r_index = find_index(r);
        cout << prefix[r_index] - prefix[l_index - 1] << endl;
    }
    return 0;
}
