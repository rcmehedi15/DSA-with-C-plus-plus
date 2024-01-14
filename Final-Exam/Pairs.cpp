#include <bits/stdc++.h>

using namespace std;

// Custom comparison function for sorting
bool comparePairs(const pair<string, int>& a, const pair<string, int>& b) {
    // Compare strings in ascending order
    if (a.first != b.first) {
        return a.first < b.first;
    }
    // If strings are the same, compare integers in descending order
    return a.second > b.second;
}

int main() {
    // Read input
    int n;
    cin >> n;

    // Vector to store pairs
    vector<pair<string, int>> pairs(n);

    // Input pairs
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    // Sort using the custom comparison function
    sort(pairs.begin(), pairs.end(), comparePairs);

    // Output the sorted pairs
    for (const auto& p : pairs) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
