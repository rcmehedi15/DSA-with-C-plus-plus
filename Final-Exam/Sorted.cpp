#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int n;
        cin >> n; // Read the size of the list

        set<int> unique_values; // To store unique values
        vector<int> values;     // To store the input values

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            unique_values.insert(x); // Insert into set to keep it unique
        }

        // Copy unique values from set to vector
        values.assign(unique_values.begin(), unique_values.end());

        // Sort the vector
        sort(values.begin(), values.end());

        // Print the sorted and unique values
        for (int value : values) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}
