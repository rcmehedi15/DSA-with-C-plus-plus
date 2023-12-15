#include <iostream>
#include <list>
#include <algorithm>  // Add this header for find
#include <string>

using namespace std;

class WebBrowser {
private:
    list<string> history;
    list<string>::iterator current;

public:
    WebBrowser(const list<string>& addresses) {
        history = addresses;
        current = history.begin();
    }

    void visit(const string& address) {
        auto it = find(history.begin(), history.end(), address);
        if (it != history.end()) {
            current = it;
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void next() {
        if (std::next(current) != history.end()) {
            ++current;
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void prev() {
        if (current != history.begin()) {
            --current;
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }
};

int main() {
    string address;
    list<string> addresses;
    
    // Input the doubly linked list
    while (cin >> address && address != "end") {
        addresses.push_back(address);
    }

    WebBrowser browser(addresses);

    int Q;
    cin >> Q;

    string command, query;
    cin >> command >> query;

    // Handle the initial visit command
    if (command == "visit") {
        browser.visit(query);
        Q--;
    }

    // Process the remaining queries
    while (Q--) {
        cin >> command;

        if (command == "visit") {
            cin >> query;
            browser.visit(query);
        } else if (command == "next") {
            browser.next();
        } else if (command == "prev") {
            browser.prev();
        }
    }

    return 0;
}
