#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    int n;
    
    // Input the initial size of the set
    cin >> n;
    
    // Input elements and insert into the set
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    
    int q;
    
    // Input the number of queries
    cin >> q;
    
    while (q--)
    {
        int input;
        cin >> input;
        
        if (input == 0)
        {
            int x;
            cin >> x;
            
            // Insert element into the set
            s.insert(x);
            
            // Check if the set is not empty and print the smallest element
            if (!s.empty())
                cout << *s.begin() << endl;
            else
                cout << "Empty" << endl;
        }
        else if (input == 1)
        {
            // Check if the set is not empty and print the smallest element
            if (!s.empty())
                cout << *s.begin() << endl;
            else
                cout << "Empty" << endl;
        }
        else if (input == 2)
        {
            // Check if the set is not empty
            if (!s.empty())
            {
                // Erase the smallest element
                s.erase(*s.begin());
                
                // Check if the set is not empty and print the smallest element
                if (!s.empty())
                    cout << *s.begin() << endl;
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
        else
            cout << "Empty" << endl;
    }

    return 0;
}
