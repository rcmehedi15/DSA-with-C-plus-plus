#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Read input size
    int N;
    cin >> N;

    // Read array A
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Calculate prefix sum
    vector<long long> prefixSum(N);
    prefixSum[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefixSum[i] = prefixSum[i - 1] + A[i];
    }

    // Print prefix sum array in reverse order
    for (int i = N - 1; i >= 0; --i) {
        cout << prefixSum[i] << " ";
    }

    return 0;
}
