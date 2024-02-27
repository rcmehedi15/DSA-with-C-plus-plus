#include <bits/stdc++.h>
using namespace std;

// Memoization table to store results of subproblems
unordered_map<int, bool> memo;

// Function to check if it's possible to reach N from 1
bool canReach(int i, int N) {
    // Base cases
    if (i == N)
        return true;
    else if (i > N)
        return false;
    
    // Check if the result for the current position is already calculated
    if (memo.find(i) != memo.end())
        return memo[i];
    
    // Recursive cases
    bool result = canReach(i + 3, N) || canReach(i * 2, N);
    
    // Store the result for current position in memoization table
    memo[i] = result;
    
    return result;
}

int main() {
    int T;
    cin >> T; // Number of test cases
    
    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N; // Value of N for current test case
        
        // Check if it's possible to reach N from 1
        if (canReach(1, N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        
        // Clear memoization table for each test case
        memo.clear();
    }
    
    return 0;
}
