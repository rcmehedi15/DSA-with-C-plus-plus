#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() : head(nullptr) {}

    void insert(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    int findDifference() {
        if (!head) {
            return 0;
        }

        int max_value = INT_MIN;
        int min_value = INT_MAX;

        Node* current = head;
        while (current) {
            max_value = max(max_value, current->data);
            min_value = min(min_value, current->data);
            current = current->next;
        }

        return max_value - min_value;
    }
};

int main() {
    SinglyLinkedList linkedList;

    // Input processing
    int value;
    while (cin >> value && value != -1) {
        linkedList.insert(value);
    }

    // Output the difference
    cout << linkedList.findDifference() << endl;

    return 0;
}
