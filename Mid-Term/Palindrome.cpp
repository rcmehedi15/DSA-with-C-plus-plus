#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Function to insert a node at the end of the doubly linked list
Node* insertEnd(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}

// Function to check if the doubly linked list forms a palindrome
bool isPalindrome(Node* head) {
    if (!head) {
        return true;
    }

    Node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }

    while (head != tail) {
        if (head->data != tail->data) {
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main() {
    Node* head = nullptr;
    int val;

    // Input loop to build the doubly linked list
    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        head = insertEnd(head, val);
    }

    // Check if the doubly linked list forms a palindrome or not
    if (isPalindrome(head)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    // Deallocate memory by deleting all nodes
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
