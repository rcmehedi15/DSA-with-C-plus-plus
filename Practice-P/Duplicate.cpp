#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> elements;
    bool hasDuplicate = false;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (!elements.insert(x).second) {
            hasDuplicate = true;
            break;
        }
    }

    cout << (hasDuplicate ? "YES" : "NO") << endl;

    return 0;
}
