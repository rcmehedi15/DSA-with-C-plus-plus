#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

bool areListsEqual(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    if (head1 != nullptr || head2 != nullptr) {
        return false;
    }

    return true; 
}

int main() {
   
    int value;
    cin >> value;
    Node* head1 = new Node(value);
    Node* current1 = head1;

    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        current1->next = new Node(value);
        current1 = current1->next;
    }

    
    cin >> value;
    Node* head2 = new Node(value);
    Node* current2 = head2;

    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        current2->next = new Node(value);
        current2 = current2->next;
    }

    
    if (areListsEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

  
    while (head1 != nullptr) {
        Node* temp = head1;
        head1 = head1->next;
        delete temp;
    }

    while (head2 != nullptr) {
        Node* temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
