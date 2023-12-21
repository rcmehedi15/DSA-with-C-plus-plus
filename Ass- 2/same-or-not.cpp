#include <bits/stdc++.h>

using namespace std;

int main() {
    // Input
    int n, m;
    cin >> n >> m;

    stack<int> stk;
    queue<int> q;

    // Input stack
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        stk.push(x);
    }

    // Input queue
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    // Check if stack and queue are the same
    while (!stk.empty() && !q.empty()) {
        if (stk.top() == q.front()) {
            stk.pop();
            q.pop();
        } else {
            break;
        }
    }

    // Output result
    if (stk.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
