#include<bits/stdc++.h>
using namespace std;

pair<int, int> maxWaterContainer(const vector<int>& heights) {
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < heights.size(); ++i) {
        pq.push({heights[i], i});
    }
    
    pair<int, int> maxHeight1 = pq.top();
    pq.pop();
    pair<int, int> maxHeight2 = pq.top();
    pq.pop();
    
    return {min(maxHeight1.second, maxHeight2.second), max(maxHeight1.second, maxHeight2.second)};
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        pair<int, int> indices = maxWaterContainer(heights);
        cout << indices.first << " " << indices.second << endl;
    }

    return 0;
}
