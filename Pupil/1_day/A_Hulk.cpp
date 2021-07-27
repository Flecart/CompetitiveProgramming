#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    cin >> i;

    bool love = false;

    while (i)
    {
        if (love)
        {
            if (i == 1)
            {
                cout << "I love it";
                break;
            }

            cout << "I love that ";
        }
        else
        {
            if (i == 1)
            {
                cout << "I hate it";
                break;
            }

            cout << "I hate that ";
        }
        i -= 1;
        love = love ? false : true;
    }
}