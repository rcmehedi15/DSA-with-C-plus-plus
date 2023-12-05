#include<bits/stdc++.h>
using namespace std;
int main()
{
    // vector <int> v; type -1
    // vector <int> v(2); type -2
    // vector <int> v(2,3); type -3
    // vector<int> v(5,10);
    vector<int> v2(2,100);
    vector<int> v(v2);
    for(int i=0; i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<v.size()<<endl;
    return 0;
}