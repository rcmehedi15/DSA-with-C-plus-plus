#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insert_tree()
{
    int value;
    cin >> value;
    Node *root;
    if (value == -1)
        root = NULL;
    else
        root = new Node(value);
    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int lef, rit;
        cin >> lef >> rit;
        Node *newValueLeft;
        Node *newValueRight;
        if (lef == -1)
            newValueLeft = NULL;
        else
            newValueLeft = new Node(lef);
        if (rit == -1)
            newValueRight = NULL;
        else
            newValueRight = new Node(rit);

        p->left = newValueLeft;
        p->right = newValueRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void LevelFindNodes(Node *root)
{
    int Level;
    cin >> Level;
    if (root == NULL)
    {
        cout << "Invalid" << endl;
        return;
    }
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    int Levels = 0;
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        Node *node = p.first;
        int level = p.second;
        Levels = level;
        q.pop();

        // main work;
        if (Level == level)
        {
            cout << node->value << " ";
        }

        if (node->left)
        {
            q.push({node->left, level + 1});
        }
        if (node->right)
        {
            q.push({node->right, level + 1});
        }
    }
    if (Level > Levels)
    {
        cout << "Invalid" << endl;
    }
}

int main()
{
    Node *root = insert_tree();
    LevelFindNodes(root);
    return 0;
}
