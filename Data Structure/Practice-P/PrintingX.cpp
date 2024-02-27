#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Check if N is an odd positive integer
    if (N % 2 == 0 || N < 1) {
        cout << "Invalid input. N should be a positive odd integer." << endl;
        return 1; // Exit with an error code
    }

    // Loop through each row
    for (int i = 0; i < N; ++i) {
        // Loop through each column
        for (int j = 0; j < N; ++j) {
            // Check if the current position is part of the X pattern
            if (i == j) {
                cout << "\\";
            } else if (i + j == N - 1) {
                cout << "/";
            } else {
                cout << " ";
            }
        }

        // Move to the next line after each row
        cout << endl;
    }

    return 0;
}
