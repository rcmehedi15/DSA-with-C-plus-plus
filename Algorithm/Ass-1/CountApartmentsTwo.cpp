#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& matrix, vector<vector<bool>>& visited, int i, int j, int& roomSize) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] == '#' || visited[i][j]) {
        return;
    }

    visited[i][j] = true;
    roomSize++;

    // Explore neighbors in all four directions
    dfs(matrix, visited, i + 1, j, roomSize);
    dfs(matrix, visited, i - 1, j, roomSize);
    dfs(matrix, visited, i, j + 1, roomSize);
    dfs(matrix, visited, i, j - 1, roomSize);
}

vector<int> countApartments(vector<vector<char>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    vector<int> apartmentSizes;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == '.' && !visited[i][j]) {
                int roomSize = 0;
                dfs(matrix, visited, i, j, roomSize);
                apartmentSizes.push_back(roomSize);
            }
        }
    }

    sort(apartmentSizes.begin(), apartmentSizes.end());
    return apartmentSizes;
}

int main() {
    int height, width;
    cin >> height >> width;

    vector<vector<char>> matrix(height, vector<char>(width));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cin >> matrix[i][j];
        }
    }

    vector<int> apartmentSizes = countApartments(matrix);

    if (apartmentSizes.empty()) {
        cout << "0" << endl;
    } else {
        for (int size : apartmentSizes) {
            cout << size << " ";
        }
        cout << endl;
    }

    return 0;
}
