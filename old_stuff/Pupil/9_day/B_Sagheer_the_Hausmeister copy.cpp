#include <bits/stdc++.h>

using namespace std;
#define ll long long

// This copy of the java solution here https://ideone.com/egb6Vr
// Doesnt work and i don know why

int n, m;

int main()
{
    cin >> n >> m;

    int maxFloor = -1;
    int left[n], right[n];
    
    for (int i = 0; i < n; i++)
    {
        left[i] = m + 1;
    }
    

    for(int i = n - 1; i >= 0; i--)
    {
        string next;
        cin >> next;
        reverse(next.begin(), next.end());
        for (int j = 0; j < m + 2; j++)
        {
            if (next[j] == '1')
            {
                right[i] = j;
                if (maxFloor == -1)
                {
                    maxFloor = i;
                }
            }
        }

        for (int j = m + 1; j >= 0; j--)
        {
            if (next[j] == '1')
                left[i] = j;
        }
        
        
    }
    int ans = INT_MAX;


    for (int stairs = 0; stairs < (1 << n - 1); stairs++)
    {
        int cur = 0, room = 0, floor = 0;
        while (floor <= maxFloor)
        {
            if (room == 0)
            {
                cur += right[floor] - room;
                room = right[floor];
            }
            else
            {
                cur += room - left[floor];
                room = left[floor];
            }

            if (floor == maxFloor)
                break;

            int goUp = (stairs & (1 << floor)) == 0 ? 0 : m + 1;

        
            cur += abs(goUp - room) + 1;

            room = goUp;
            floor += 1;
        }
        
        ans = min(ans, cur);
    }
    cout << ans;
    return 0;
}