#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    while(cin >> start)
    {
        bool ans[] = {1, 1, 1};

        stack<int> s;
        queue<int> q;
        priority_queue<int> p;

        while (start--)
        {
            int first, second;

            cin >> first >> second;

            if (first == 1)
            {
                s.push(second);
                q.push(second);
                p.push(second);
            }
            else
            {
                int temp;

                if (!s.empty())
                {
                    temp = s.top();
                    s.pop();

                    if (temp != second)
                        ans[0] = false;
                }
                else    
                    ans[0] = false;

                if (!q.empty())
                {
                    temp = q.front();
                    q.pop();
                    if (temp != second)
                        ans[1] = false;
                }
                else
                    ans[1] = false;

                if (!p.empty())
                {
                    temp = p.top();
                    p.pop();
                    if (temp != second)
                        ans[2] = false;
                }
                else
                    ans[2] = false;
            }
        }

        short ones = 0;
        for (int i = 0; i < 3; i++)
        {
            if (ans[i])
                ones += 1;
        }

        if (ones == 0)
        {
            cout << "impossible\n";
        }
        else if (ones == 1)
        {
            if (ans[0])
                cout << "stack\n";
            else if (ans[1])
                cout << "queue\n";
            else
                cout << "priority queue\n";
        }
        else
            cout << "not sure\n";
    }

    return 0;
}