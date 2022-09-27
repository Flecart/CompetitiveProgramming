#include <bits/stdc++.h>

using namespace std;

int main()
{
    int teleports;

    int target;
    cin >> teleports >> target;

    int current_state = 0;
    bool canReach = true;
    while(teleports--)
    {
        int begin ,end;
        cin >> begin >> end;

        if (begin <= current_state)
        {
            if (current_state < end)
                current_state = end;
        }
        else
        {
            canReach = false;
            break;
        }

        if (current_state >= target)
        {
            canReach = true;
            break;
        }
    }

    if (current_state < target)
    {
        canReach = false;
    }
    

    if (canReach)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}