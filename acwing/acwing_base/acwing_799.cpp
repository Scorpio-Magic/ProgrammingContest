/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: double pointer
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int num[maxn], cnt[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n; cin >> n;
    int ans = 0;
    for (int ed = 0, st = 0; ed < n; ++ed) {
        cin >> num[ed];
        cnt[num[ed]]++;
        while (cnt[num[ed]] > 1) {
            cnt[num[st]]--;
            ++st;
        }
        ans = max(ans, ed - st + 1);
    }
    cout << ans << endl;
    return 0;
}
