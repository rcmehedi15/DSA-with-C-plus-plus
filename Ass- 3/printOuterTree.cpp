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
        Node *leftNewValue;
        Node *rightNewValue;
        if (lef == -1)
            leftNewValue = NULL;
        else
            leftNewValue = new Node(lef);
        if (rit == -1)
            rightNewValue = NULL;
        else
            rightNewValue = new Node(rit);

        p->left = leftNewValue;
        p->right = rightNewValue;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void ValueOrderLevel(Node *root)
{
    queue<Node *> q;
    q.push(root);
    stack<Node *> stkNod;
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        stkNod.push(f);

        if (f->left)
            q.push(f->left);
        else
        {
            if (f->right)
                q.push(f->right);
        }
    }

    while (!stkNod.empty())
    {
        Node *p = stkNod.top();
        cout << p->value << " ";
        stkNod.pop();
    }
}
void ValueOrderLevelTwo(Node *root)
{
    Node *rightNode = root->right;
    queue<Node *> q;
    q.push(rightNode);
    while (!q.empty())
    {
        Node *f = q.front();
        q.pop();
        cout << f->value << " ";

        if (f->right)
        {
            if (f->right)
                q.push(f->right);
        }
        else
        {
            if (f->left)
                q.push(f->left);
        }
    }
}

int main()
{
    Node *root = insert_tree();
    if (root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            cout << root->value;
        }
        else
        {
            if (root->left)
            {
                ValueOrderLevel(root);
            }
            if (root->right)
            {
                if (!root->left)
                    cout << root->value << " ";
                ValueOrderLevelTwo(root);
            }
        }
    }
    return 0;
}
