#include <bits/stdc++.h>

using namespace std;
#define ll long long

int space, M, lastValue, dominos[2][14];

int memo[7][1 << 14];


bool dp(int toCompare, int used)
{
    if (bitset<15>(used).count() == space)
        return toCompare == lastValue;
    if (memo[toCompare][used] != -1)
        return memo[toCompare][used];

    bool found = false;

    for (int i = 0; !found && i < M; i++)
    {
        if ((used & 1 << i) == 0)
        {
            if (toCompare == dominos[0][i])
                found |= dp(dominos[1][i], used | 1 << i);
            if (toCompare == dominos[1][i])
                found |= dp(dominos[0][i], used | 1 << i);
        }
    }

    return memo[toCompare][used] = found;
    
}

int main()
{
    while (true)
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 1 << 14; j++)
            {
                memo[i][j] = -1;
            }
            
        }
        
        cin >> space;
        if (space == 0)
            break;

        cin >> M;

        int firstValue, garbage;
        cin >> garbage >> firstValue;
        cin >> lastValue >> garbage;
        for (int i = 0; i < M; i++)
        {
            cin >> dominos[0][i];
            cin >> dominos[1][i];
        }

        dp(firstValue, 0) ? cout << "YES\n" : cout << "NO\n";
        
    }

    return 0;
}
