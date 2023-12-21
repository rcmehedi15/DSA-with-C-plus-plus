#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    stack<int> stk;
    queue<int> que;

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
        que.push(x);
    }

    // Check if stack and queue are the same
    while (!stk.empty() && !que.empty()) {
        if (stk.top() == que.front()) {
            stk.pop();
            que.pop();
        } else {
            break;
        }
    }

    // Output result
    if (stk.empty() && que.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
