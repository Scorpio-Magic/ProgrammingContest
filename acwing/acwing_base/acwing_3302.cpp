/*
    Author: PeterAn
    Date: 2023-07-22
    Algorithm: calculate the value of an expression
*/

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

stack<int> num;
stack<char> op;

void evaluate() {
    int b = num.top(); num.pop();
    int a = num.top(); num.pop();
    char ch = op.top(); op.pop();
    int value = 0;
    if ('+' == ch) value = a + b;
    else if ('-' == ch) value = a - b;
    else if ('*' == ch) value = a * b;
    else if ('/' == ch) value = a / b;
    num.push(value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str; cin >> str;

    for (size_t i = 0; i < str.size(); ++i) {
        auto ch = str[i];
        if (isdigit(ch)) {
            int value = 0;
            size_t j = i;
            while (j < str.size() && isdigit(str[j])) {
                value = value * 10 + str[j] - '0';
                ++j;
            }
            i = j - 1;
            num.push(value);
        } else if ('(' == ch) {
            op.push(ch);
        } else if (')' == ch) {
            while ('(' != op.top()) evaluate();
            op.pop();
        } else {
            while (op.size() && pr[op.top()] >= pr[ch]) evaluate();
            op.push(ch);
        }
    }

    while (op.size()) evaluate();
    cout << num.top() << endl;
    return 0;
}
