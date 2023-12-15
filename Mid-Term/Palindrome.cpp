#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array forms a palindrome
bool isPalindrome(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) {
        if (arr[left] != arr[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    vector<int> arr;
    int val;

    while (true) {
        cin >> val;
        if (val == -1) {
            break;
        }
        arr.push_back(val);
    }

    if (isPalindrome(arr)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
