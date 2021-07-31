#include <bits/stdc++.h>

using namespace std;
#define ll long long

set<vector<int>, greater<vector<int>> > possible;

int t, n;

void generate(vector<int> current, int sum, priority_queue<int> toTry)
{
    if (sum > t)
        return;


    if (sum == t)
    {
        possible.insert(current);
        return;
    }

    while (!toTry.empty())
    {
        int tmp = toTry.top();
        current.push_back(tmp);
        toTry.pop();
        generate(current, sum + tmp, toTry);
        current.pop_back();
    }
    
    return;
}

int main()
{
    while (true)
    {
        possible.clear();
        cin >> t >> n;

        if (t == 0 && n == 0)
            break;
        priority_queue<int> toTry;

        while (n--)
        {
            int temp;
            cin >> temp;
            toTry.push(temp);
        }
        
        generate(vector<int>(), 0, toTry);

        cout << "Sums of " << t << ":\n";

        if (possible.empty())
            cout << "NONE\n";
        else
        {
             for (auto i : possible)
            {
                vector<int>::iterator last = i.end();
                last--;

                for (auto it = i.begin(); it != i.end(); it++)
                {
                    cout << *it;
                    if (it != last)
                        cout << "+";
                }
                cout << "\n";
            }
        }
       
        
    }
    return 0;
}