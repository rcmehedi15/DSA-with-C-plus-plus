#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    queue<string> line;

    for (int i = 0; i < n; i++)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            string name;
            cin >> name;
            line.push(name);
        }
        else if (command == 1)
        {
            if (!line.empty())
            {
                cout << line.front() << endl;
                line.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}
