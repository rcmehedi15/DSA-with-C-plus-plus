#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> myList, reverseList;
    int q, x;
    size_t v;
    cin >> q;

    while (q--)
    {
        cin >> x >> v;

        if (x == 0)
            myList.push_front(v);
        else if (x == 1)
            myList.push_back(v);
        else if (x == 2 && v < myList.size())
            myList.erase(next(myList.begin(), v));

        cout << "L -> ";
        for (auto val : myList)
            cout << val << " ";
        cout << "\nR -> ";
        reverseList.assign(myList.rbegin(), myList.rend());
        for (auto val : reverseList)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
