#include <bits/stdc++.h>
using namespace std;

// Define the structure for a node in the linked list
struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

// Function to find the index of a given value in the linked list
int findIndex(Node* head, int x) {
    int index = 0;
    
    // Traverse the linked list
    while (head != nullptr) {
        if (head->data == x) {
            return index; // Value found, return the index
        }
        head = head->next;
        index++;
    }
    
    return -1; // Value not found in the linked list
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        // Input the linked list
        int value;
        cin >> value;
        Node* head = new Node(value);
        Node* current = head;

        while (true) {
            cin >> value;
            if (value == -1) {
                break;
            }
            current->next = new Node(value);
            current = current->next;
        }

        // Input the value to search
        int X;
        cin >> X;

        // Find the index of X in the linked list
        int result = findIndex(head, X);

        // Output the result
        cout << result << endl;

        // Deallocate memory for the linked list
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
