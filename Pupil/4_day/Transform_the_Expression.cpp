#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    char c;

    cin >> start;

    // primo escape
    cin.get(c);
    while(start--)
    {
        stack<char> rpn;
        vector<char> ans;
        while (cin.get(c))
        {
            if (c == '\n')
                break;  
            
            if (isalpha(c))
            {
                ans.push_back(c);
                continue;
            }

            if (c == ')')
            {
                while (rpn.top() != '(' && !rpn.empty())
                {
                    ans.push_back(rpn.top());
                    rpn.pop();
                }
                if (rpn.top() == '(')
                    rpn.pop();
                continue;
            }

            rpn.push(c);
        }

        for (vector<char>::iterator i = ans.begin(); i != ans.end(); i++)
        {
            cout << *i;
        }
        
        cout << '\n';
    }

    return 0;
}