#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to calculate the height of a binary tree
int height(TreeNode* root) {
    if (!root)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Function to check if a binary tree is perfect
bool isPerfect(TreeNode* root) {
    if (!root)
        return true;

    int treeHeight = height(root);
    int totalNodes = pow(2, treeHeight) - 1;

    int countNodes = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (current) {
            countNodes++;
            q.push(current->left);
            q.push(current->right);
        }
    }

    return countNodes == totalNodes;
}

int main() {
    // Parse input in level order
    vector<int> input;
    int val;
    while (cin >> val) {
        input.push_back(val);
    }

    // Build the binary tree
    TreeNode* root = nullptr;
    queue<TreeNode*> q;
    size_t i = 0;
    if (i < input.size()) {
        root = new TreeNode(input[i++]);
        q.push(root);
    }

    while (!q.empty() && i < input.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (input[i] != -1) {
            current->left = new TreeNode(input[i]);
            q.push(current->left);
        }
        i++;

        // Right child
        if (i < input.size() && input[i] != -1) {
            current->right = new TreeNode(input[i]);
            q.push(current->right);
        }
        i++;
    }

    // Check if the binary tree is perfect
    if (isPerfect(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
