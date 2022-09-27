#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    if (start == 1)
    {
        int temp;
        cin >> temp;
        if (temp == 15)
            cout << "DOWN";
        else if (temp == 0)
            cout << "UP";
        else
            cout << -1;
        return 0;
    }

    int lastOne = -1;
    int current = -1;
    while(start--)
    {
        lastOne = current;
        cin >> current;
    }

    if (lastOne < current)
    {
        if (current == 15)
        {
            cout << "DOWN";
        }
        else
            cout << "UP";
    }
    else
    {
        if (current == 0)
        {
            cout << "UP";
        }
        else 
            cout << "DOWN";
    }

    return 0;
}