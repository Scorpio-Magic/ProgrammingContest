/*
    Author: PeterAn
    Date: 2023-07-24
    Algorithm: bfs and hash
*/

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int bfs(string start) {
    string end = "12345678x";
    queue<string> que;
    unordered_map<string, int> mp;
    que.push(start);
    mp[start] = 0;
    while (que.size()) {
        string now = que.front(); que.pop();
        if (now == end) return mp[now];
        int k = now.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
            string next = now;
            swap(next[k], next[nx * 3 + ny]);
            if (mp.count(next)) continue;
            mp[next] = mp[now] + 1;
            que.push(next);
        }        
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string start = "";
    string ch;
    for (int i = 0; i < 9; ++i) {
        cin >> ch;
        start += ch;
    }
    cout << bfs(start) << endl;
    return 0;
}
