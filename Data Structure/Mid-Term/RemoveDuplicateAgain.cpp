#include <bits/stdc++.h>

using namespace std;

int main() {
    // Declare a list to store the linked list
    list<int> linkedList;

    // Declare a set to store unique values
    unordered_set<int> uniqueValues;

    // Input values until -1 is encountered
    int value;
    while (cin >> value && value != -1) {
        // Check if the value is already in the set
        if (uniqueValues.find(value) == uniqueValues.end()) {
            // If not in the set, add to both the set and the linked list
            uniqueValues.insert(value);
            linkedList.push_back(value);
        }
    }

    // Sort the linked list in ascending order
    linkedList.sort();

    // Output the final linked list
    for (const auto &element : linkedList) {
        cout << element << " ";
    }

    return 0;
}
