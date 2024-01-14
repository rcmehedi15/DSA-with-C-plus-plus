#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int mark;
    Student(string name, int roll, int mark)
    {
        this->name = name;
        this->roll = roll;
        this->mark = mark;
    }
};

class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.mark < b.mark)
        {
            return true;
        }
        else if (a.mark == b.mark)
        {
            if (a.roll > b.roll)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int r, m;
        cin >> name >> r >> m;
        Student StudentObj(name, r, m);
        pq.push(StudentObj);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int cmd;
        cin >> cmd;

        if (cmd == 0)
        {
            string name;
            int r, m;
            cin >> name >> r >> m;
            Student StudentObj(name, r, m);
            pq.push(StudentObj);

            if (!pq.empty())
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
            else
                cout << "Empty" << endl;
        }
        else if (cmd == 1)
        {
            if (!pq.empty())
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
            else
                cout << "Empty" << endl;
        }
        else if (cmd == 2)
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().mark << endl;
                else
                    cout << "Empty" << endl;
            }
        }
    }

    return 0;
}