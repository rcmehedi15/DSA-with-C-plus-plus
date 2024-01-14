#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(); // consume the newline character after reading n

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        string word;
        stringstream ss(line);
        map<string, int> mp;

        string ans; // Updated: to store the word with maximum frequency
        int mx = 0; // Updated: to store the maximum frequency

        while (ss >> word)
        {
            mp[word]++;
            if (mp[word] > mx)
            {
                mx = mp[word];
                ans = word;
            }
        }

        cout << ans << " " << mx << endl;
    }

    return 0;
}
