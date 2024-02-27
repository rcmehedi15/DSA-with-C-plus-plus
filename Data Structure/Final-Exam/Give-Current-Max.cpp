#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks == b.marks)
            return a.roll > b.roll;
        return a.marks < b.marks;
    }
};

void print_(Student a)
{
    cout << a.name << " " << a.roll << " " << a.marks << endl;
}

int main()
{
    priority_queue<Student, vector<Student>, cmp> pq;

    int n;
    cin >> n;
    while (n--)
    {
        Student a;
        cin >> a.name >> a.roll >> a.marks;
        pq.push(a);
    }

    int t;
    cin >> t;
    while (t--)
    {
        int c;
        cin >> c;

        if (c == 0)
        {
            Student a;
            cin >> a.name >> a.roll >> a.marks;
            pq.push(a);
            print_(pq.top());
        }
        else if (c == 1)
        {
            if (!pq.empty())
                print_(pq.top());
            else
                cout << "Empty" << endl;
        }
        else if (c == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                    print_(pq.top());
                else
                    cout << "Empty\n";
            }
            else
                cout << "Empty\n";
        }
    }

    return 0;
}
