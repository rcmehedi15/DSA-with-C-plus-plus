#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        string line;
        getline(cin, line);
        string word;
        stringstream ss(line);
        map<string, int> mp;
        while (ss >> word)
        {
            mp[word]++;
            cout << word << ", ";
        }
        int max = 0;
        string name;
        pair<string, int> p;
        for (auto it : mp)
        {
            if (it.second > max)
            {
                max = it.second;
                name = it.first;
                p.first = it.first;
                p.second = it.second;
            }
        }
       
        cout << p.first << " " << p.second << endl;
        cout << name << " " << max << endl;
    }

    return 0;
}