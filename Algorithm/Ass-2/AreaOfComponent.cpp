#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<bool>>& visited, vector<vector<char>>& matrix) {
    return x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == '.' && !visited[x][y];
}

int bfs(int x, int y, vector<vector<bool>>& visited, vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int area = 0;

    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        area++;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < 4; i++) {
            int newX = cur.first + dx[i];
            int newY = cur.second + dy[i];
            if (isValid(newX, newY, n, m, visited, matrix)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return area;
}

int minimum_component_area(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int minArea = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                int area = bfs(i, j, visited, matrix);
                minArea = min(minArea, area);
            }
        }
    }

    return minArea == INT_MAX ? -1 : minArea;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << minimum_component_area(matrix) << endl;

    return 0;
}
