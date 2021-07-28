#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool incident = false;

    bool road[4][4];

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> road[i][j];
        }
    }


    for (int i = 0; i < 4; i++)
    {
        if (road[i][3])
        {
            if (road[(i + 1) % 4][0] || road[(i + 2) % 4][1] || road[(i + 3) % 4][2])
            {
                incident = true;
                break;
            }

            if (road[i][0] || road[i][1] || road[i][2])
            {
                incident = true;
                break;
            }
        }
    }
    
    if (incident)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    // if (road[3][3])
    // {
    //     if (road[0][0] || road[1][1] || road[2][2])
    //     {
    //         incident = true;
    //     }
    // }
    // if (road[3][2])
    // {
    //     if (road[3][0] || road[0][1] || road[1][2])
    //     {
    //         incident = true;
    //     }
    // }
    // if (road[3][1])
    // {
    //     if (road[2][0] || road[3][1] || road[0][2])
    //     {
    //         cout << "hey";
    //     }
    // }
    
    
    
    return 0;
}