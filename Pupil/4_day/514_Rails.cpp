#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int start;
        cin >> start;

        if (start == 0)
        {
            break;
        }
        while (true)
        {
            stack<int> myStack;
            queue<int> permutation;
            bool exit = false;
            for (int i = 0; i < start; i++)
            {   
                int temp;
                cin >> temp;    

                if (temp == 0)
                {
                    cout << '\n';
                    exit = true;
                    break;
                }
                permutation.push(temp);
            }

            if (exit)
            {
                break;
            }
            
            for (int i = 0; i < start; i++)
            {
                myStack.push(i + 1);

                // cout << myStack.top();
                while (permutation.front() == myStack.top())
                {
                    myStack.pop();
                    permutation.pop();

                    if (myStack.empty() || permutation.empty())
                        break;
                }
            }

            if (myStack.empty())
            {
                cout << "Yes\n";
            }
            else
                cout << "No\n";   
        }
    }

    return 0;
}