/*
    Author: PeterAn
    Date: 2023-07-20
    Algorithm: high precision addition
*/

#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

vector<int> add(vector<int> &A, vector<int> &B) {
    if (A.size() < B.size()) return add(B, A);
    vector<int> C;
    int t = 0;
    for (std::size_t i = 0; i < A.size(); i++) {
        t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t) C.push_back(t);
    return C;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, b;
    vector<int> A, B;
    cin >> a >> b;

    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');

    while (A.size() > 1 && A.back() == 0) A.pop_back();
    while (B.size() > 1 && B.back() == 0) B.pop_back();
    auto C = add(A, B);
    
    for (int i = C.size() - 1; i >= 0; i--) cout << C[i];

    return 0;
}
