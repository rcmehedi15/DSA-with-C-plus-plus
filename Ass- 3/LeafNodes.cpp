#include<bits/stdc++.h>

using namespace std;

// Define the structure for the tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to construct a binary tree from level order traversal
TreeNode* constructTree(vector<int>& levelOrder) {
    if (levelOrder.empty() || levelOrder[0] == -1) {
        return NULL;
    }

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(levelOrder[0]);
    q.push(root);

    size_t i = 1;
    while (!q.empty() && i < levelOrder.size()) {
        TreeNode* current = q.front();
        q.pop();

        int leftValue = levelOrder[i++];
        if (leftValue != -1) {
            current->left = new TreeNode(leftValue);
            q.push(current->left);
        }

        if (i < levelOrder.size()) {
            int rightValue = levelOrder[i++];
            if (rightValue != -1) {
                current->right = new TreeNode(rightValue);
                q.push(current->right);
            }
        }
    }

    return root;
}

// Function to perform in-order traversal and collect leaf node values
void getLeafNodes(TreeNode* root, vector<int>& leafNodes) {
    if (root) {
        if (!root->left && !root->right) {
            leafNodes.push_back(root->val);
        }

        getLeafNodes(root->left, leafNodes);
        getLeafNodes(root->right, leafNodes);
    }
}

int main() {
    // Read input
    vector<int> levelOrder;
    int val;
    while (cin >> val) {
        levelOrder.push_back(val);
    }

    // Construct the binary tree
    TreeNode* root = constructTree(levelOrder);

    // Collect leaf nodes and sort in descending order
    vector<int> leafNodes;
    getLeafNodes(root, leafNodes);
    sort(leafNodes.rbegin(), leafNodes.rend());

    // Print the result
    for (int value : leafNodes) {
        cout << value << " ";
    }

    return 0;
}
