#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, X;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cin >> M;

    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }

    cin >> X;

    // Insert array B into array A at index X
    A.insert(A.begin() + X, B.begin(), B.end());

    // Output the final array A using ostream_iterator
    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    
    return 0;
}
