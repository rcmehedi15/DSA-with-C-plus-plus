#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    list<int> l;
    list<int>::iterator it = l.begin();

    for (int i = 0; i < Q; i++) {
        int x, v;
        cin >> x >> v;

        if (x < 0 || x > static_cast<int>(l.size())) {
            cout << "Invalid" << endl;
            continue;
        }

        if (x == 0) {
            l.push_front(v);
            it = l.begin();
        } else if (x == static_cast<int>(l.size())) {
            l.push_back(v);
            it = l.end();
            it--;
        } else {
            advance(it, x);
            l.insert(it, v);
            it = l.begin();  // Reset the iterator to the beginning
        }

        cout << "L -> ";
        for (auto itr = l.begin(); itr != l.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;

        cout << "R -> ";
        for (auto ritr = l.rbegin(); ritr != l.rend(); ritr++) {
            cout << *ritr << " ";
        }
        cout << endl;
    }

    return 0;
}
