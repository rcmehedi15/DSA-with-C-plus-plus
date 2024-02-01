#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& matrix, vector<vector<bool>>& visited, size_t i, size_t j) {
    // Base cases to check if the cell is out of bounds or already visited
    if (i >= matrix.size() || j >= matrix[0].size() || visited[i][j] || matrix[i][j] == '-')
        return;

    // Mark the current cell as visited
    visited[i][j] = true;

    // Explore neighboring cells in all four directions
    dfs(matrix, visited, i - 1, j); // Up
    dfs(matrix, visited, i + 1, j); // Down
    dfs(matrix, visited, i, j - 1); // Left
    dfs(matrix, visited, i, j + 1); // Right
}

bool areInSameComponent(vector<vector<char>>& matrix, size_t startX, size_t startY, size_t endX, size_t endY) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    // Create a 2D array to mark visited cells
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    // Perform DFS from the start cell
    dfs(matrix, visited, startX, startY);

    // Check if the end cell is visited after DFS
    return visited[endX][endY];
}

int main() {
    size_t rows, cols;
    cin >> rows >> cols;

    // Input matrix
    vector<vector<char>> matrix(rows, vector<char>(cols));
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Input start and end cells
    size_t startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    // Check if the start and end cells are in the same component
    if (areInSameComponent(matrix, startX, startY, endX, endY)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
