#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_position(Node *&head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        if (temp == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insert_head(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void print_value(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

void print_reverse(Node *v)
{
    if (v == NULL)
        return;
    print_reverse(v->next);
    cout << v->val << " ";
}

int main()
{
    Node *head = NULL;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, v;
        cin >> x >> v;
        if (x > size(head))
        {
            cout << "Invalid" << endl;
        }
        else if (x == 0)
        {
            insert_head(head, v);
            cout << "L -> ";
            print_value(head);
            cout << endl;
            cout << "R -> ";
            print_reverse(head);
            cout << endl;
        }
        else
        {
            insert_position(head, x, v);
            cout << "L -> ";
            print_value(head);
            cout << endl;
            cout << "R -> ";
            print_reverse(head);
            cout << endl;
        }
    }

    return 0;
}
