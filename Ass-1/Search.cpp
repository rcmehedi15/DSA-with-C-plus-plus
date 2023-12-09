#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};

int findIndex(Node* head, int x) {
    int index = 0;
    
    while (head != nullptr) {
        if (head->data == x) {
            return index; 
        }
        head = head->next;
        index++;
    }
    
    return -1; 
}

int main() {
    int T;
    cin >> T;

    while (T--) {
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

       
        int X;
        cin >> X;

       
        int result = findIndex(head, X);

        
        cout << result << endl;
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}
