#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& matrix, int i, int j, int rows, int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == '#' || matrix[i][j] == 'x') {
        return;
    }

    matrix[i][j] = 'x';  // Mark the current room as visited

    // Explore all four directions
    dfs(matrix, i + 1, j, rows, cols);
    dfs(matrix, i - 1, j, rows, cols);
    dfs(matrix, i, j + 1, rows, cols);
    dfs(matrix, i, j - 1, rows, cols);
}

int countApartments(vector<vector<char>>& matrix, int rows, int cols) {
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '.') {
                // Found a room, perform DFS to mark connected rooms
                dfs(matrix, i, j, rows, cols);
                count++;
            }
        }
    }

    return count;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> matrix(rows, vector<char>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = countApartments(matrix, rows, cols);
    cout << result << endl;

    return 0;
}
