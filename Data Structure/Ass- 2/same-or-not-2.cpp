#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Implementing stack
    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        stk.push(x);
    }

    // Implementing queue
    queue<int> q;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Comparing stack and queue
    while (!stk.empty() && !q.empty()) {
        if (stk.top() != q.front()) {
            cout << "NO" << endl;
            return 0;
        }
        stk.pop();
        q.pop();
    }

    // Check if both are empty, meaning the order is the same
    if (stk.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
