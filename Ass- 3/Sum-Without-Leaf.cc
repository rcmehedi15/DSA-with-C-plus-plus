#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumExceptLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        // Leaf node
        return 0;
    }

    // Sum of values in non-leaf nodes
    return root->val + sumExceptLeaves(root->left) + sumExceptLeaves(root->right);
}

// Function to build a binary tree from level order traversal
TreeNode* buildTree(vector<int>& nodes, size_t index) {
    if (index >= nodes.size() || nodes[index] == -1) {
        return NULL;
    }

    TreeNode* root = new TreeNode(nodes[index]);
    root->left = buildTree(nodes, 2 * index + 1);
    root->right = buildTree(nodes, 2 * index + 2);

    return root;
}


int main() {
    // Read level order input
    vector<int> nodes;
    int value;
    while (cin >> value) {
        nodes.push_back(value);
    }

    // Build the binary tree
    TreeNode* root = buildTree(nodes, 0);

    // Calculate and output the sum of values in non-leaf nodes
    int result = sumExceptLeaves(root);
    cout << result << endl;

    return 0;
}
