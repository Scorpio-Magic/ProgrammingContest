/*
    Author: PeterAn
    Date: 2023-07-23
    Algorithm: simulating hash
*/

#include <iostream>
#include <cstring>
using namespace std;
const int modn = 100000 + 7;
int head[modn], nex[modn], val[modn], idx;

void insert_hash(int x) {
    int h = (x % modn + modn) % modn;
    val[idx] = x;
    nex[idx] = head[h];
    head[h] = idx++;
}

bool query_hash(int x) {
    int h = (x % modn + modn) % modn;
    for (int i = head[h]; i != -1; i = nex[i]) {
        if (val[i] == x) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(head, -1, sizeof(head));
    idx = 0;

    int n; cin >> n;
    while(n--) {
        string op;
        int x; cin >> op >> x;
        if ("I" == op) {
            insert_hash(x);
        } else if ("Q" == op) {
            if (query_hash(x)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}

// STL version
// #include <iostream>
// #include <set>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr); cout.tie(nullptr);

//     set<int> s;
//     int n; cin >> n;
//     while (n--) {
//         string op;
//         int x; cin >> op >> x;
//         if ("I" == op) {
//             if(s.find(x) == s.end()) s.insert(x);
//         } else if ("Q" == op) {
//             if (s.find(x) != s.end()) cout << "Yes" << endl;
//             else cout << "No" << endl;
//         }
//     }
//     return 0;
// }
