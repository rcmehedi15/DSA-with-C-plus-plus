#include <bits/stdc++.h>

using namespace std;

bool comparePairs(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.first != b.first)
    {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main()
{
    // Read input
    int n;
    cin >> n;

    // Vector to store pairs
    vector<pair<string, int>> pairs(n);

    // Input pairs
    for (int i = 0; i < n; ++i)
    {
        cin >> pairs[i].first >> pairs[i].second;
    }

    sort(pairs.begin(), pairs.end(), comparePairs);

    // Output the sorted pairs
    for (const auto &p : pairs)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
