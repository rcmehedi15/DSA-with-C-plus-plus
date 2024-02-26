#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Number of boxes

        vector<int> chocolates(n);
        int totalChocolates = 0;

        for (int i = 0; i < n; ++i) {
            cin >> chocolates[i];
            totalChocolates += chocolates[i];
        }

        // If the total number of chocolates is odd, it's impossible to divide equally
        if (totalChocolates % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        // Check if it's possible to make the sum of chocolates equal to half the total
        int target = totalChocolates / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= chocolates[i]; --j) {
                dp[j] = dp[j] || dp[j - chocolates[i]];
            }
        }

        if (dp[target]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
