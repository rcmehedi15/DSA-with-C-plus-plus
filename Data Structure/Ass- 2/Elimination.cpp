#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        stack<char> st;

        // Use size_t for i to match the type of s.length()
        for (size_t i = 0; i < s.length(); i++) {
            if (!st.empty() && s[i] == '1' && st.top() == '0') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        if (st.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
