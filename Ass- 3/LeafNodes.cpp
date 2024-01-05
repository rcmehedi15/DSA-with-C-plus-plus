#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

// Define a structure for the binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the binary tree from level order input
TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty()) return NULL;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);

    for (std::vector<std::__cxx11::basic_string<char>>::size_type i = 1; i < nodes.size(); i += 2) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != "-1") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }

        if (i + 1 < nodes.size() && nodes[i + 1] != "-1") {
            current->right = new TreeNode(stoi(nodes[i + 1]));
            q.push(current->right);
        }
    }

    return root;
}

// Function to print nodes at a specific level
void printNodesAtLevel(TreeNode* root, int level) {
    if (root == NULL || level < 0) {
        cout << "Invalid" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        // Check if the current level matches the specified level
        if (currentLevel == level) {
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();
                cout << current->val << " ";

                if (current->left != NULL) q.push(current->left);
                if (current->right != NULL) q.push(current->right);
            }
            cout << endl;
            return; // Exit the function after printing the nodes at the specified level
        }

        // Process the level without printing if it doesn't match the specified level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }

        ++currentLevel;
    }

    cout << "Invalid" << endl; // If the specified level is not found
}

int main() {
    // Input processing
    string input;
    getline(cin, input);
    istringstream iss(input);
    vector<string> nodes;
    string node;
    while (iss >> node) {
        nodes.push_back(node);
    }

    // Construct the binary tree
    TreeNode* root = buildTree(nodes);

    // Read the level from input
    int level;
    cin >> level;

    // Print nodes at the specified level
    printNodesAtLevel(root, level);

    return 0;
}
