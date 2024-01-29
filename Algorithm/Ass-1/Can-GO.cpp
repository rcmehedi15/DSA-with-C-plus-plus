#include <bits/stdc++.h>


using namespace std;

// Function Depth-First Search
bool dfs(vector<vector<char>>& building, int x, int y, int targetX, int targetY, int height, int width) {
    // Check if the current position is out of bounds or a wall
    if (x < 0 || x >= height || y < 0 || y >= width || building[x][y] == '#') {
        return false;
    }

    building[x][y] = '#';

 
    if (x == targetX && y == targetY) {
        return true;
    }

    // Recursively explore adjacent cells
    return dfs(building, x + 1, y, targetX, targetY, height, width) ||
           dfs(building, x - 1, y, targetX, targetY, height, width) ||
           dfs(building, x, y + 1, targetX, targetY, height, width) ||
           dfs(building, x, y - 1, targetX, targetY, height, width);
}

bool canGo(vector<vector<char>>& building, int height, int width, int startX, int startY, int targetX, int targetY) {
    return dfs(building, startX, startY, targetX, targetY, height, width);
}

int main() {
    int height, width;
    cin >> height >> width;

    // Input building map
    vector<vector<char>> building(height, vector<char>(width));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> building[i][j];
        }
    }

    int startX = -1, startY = -1, targetX = -1, targetY = -1;

    // Find the starting and target positions
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (building[i][j] == 'A') {
                startX = i;
                startY = j;
            } else if (building[i][j] == 'B') {
                targetX = i;
                targetY = j;
            }
        }
    }

    if (canGo(building, height, width, startX, startY, targetX, targetY)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
