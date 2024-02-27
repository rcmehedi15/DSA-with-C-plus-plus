#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the sum of non-leaf node values using level order traversal
int levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return 0; // Return 0 for an empty tree
    }

    int nonLeafNodeSum = 0;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        // Check if the current node is a leaf
        if (current->left == nullptr && current->right == nullptr) {
            // It's a leaf node, do nothing
        } else {
            // It's not a leaf node, add its raw value to nonLeafNodeSum
            nonLeafNodeSum += current->val;
        }

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    return nonLeafNodeSum;
}

// Function to build a binary tree from user input
TreeNode* buildTree() {
    int val;
    
    cin >> val;

    TreeNode* root = new TreeNode(val);
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cin >> leftVal;

        if (leftVal != -1) {
            current->left = new TreeNode(leftVal);
            q.push(current->left);
        }

        cin >> rightVal;

        if (rightVal != -1) {
            current->right = new TreeNode(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

int main() {
    // Build the binary tree based on user input
    TreeNode* root = buildTree();

    // Call the levelOrderTraversal function with the root of the tree
    int result = levelOrderTraversal(root);

    // Display the result
    cout << result << endl;

  

    return 0;
}
