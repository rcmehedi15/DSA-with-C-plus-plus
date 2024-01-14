#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n; 

        set<int> unique_values; 
        vector<int> values;     

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            unique_values.insert(x); 
        }

        values.assign(unique_values.begin(), unique_values.end());

        // Sort vector
        sort(values.begin(), values.end());

        // Print sorted and unique values
        for (int value : values) {
            cout << value << " ";
        }

        cout << endl;
    }

    return 0;
}
