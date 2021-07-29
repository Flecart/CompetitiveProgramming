#include <bits/stdc++.h>

using namespace std;

#define pp pair<pair<int,int>, int>

struct Compare 
{
    bool operator()(pp a, pp b) 
    {
        if (a.second != b.second)
            return a.second > b.second;

        return a.first.first > b.first.first;
    }
};

int main()
{
    string regi;
    cin >> regi;

    priority_queue<pp, vector<pp>, Compare> hello;
    while (regi.compare("#"))
    {
        int tmp, tmp2;
        cin >> tmp;
        cin >> tmp2;

        hello.push(make_pair(pair<int,int>(tmp, tmp2), tmp2));

        cin >> regi;
    }

    int queries;
    cin >> queries;

    while (queries--)
    {
        pp tmp = hello.top();
        hello.pop();

        cout << tmp.first.first << '\n';

        tmp.second = tmp.second + tmp.first.second;

        hello.push(tmp);
    }
    
    
    return 0;
}