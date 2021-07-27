#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    int live;
    cin >> start;
    cin >> live;
    live -= 1; // adapt index
    bool cities[start];
    int ans = 0;

    for (int i = 0; i < start; i++)
    {
        cin >> cities[i];
    }

    int loopForChecking = max(live, start - live);

    for (int i = 0; i <= loopForChecking; i++)
    {
        short upper = live + i;
        short lower = live - i;
        if (upper < start && lower >= 0)
        {
            if (cities[upper] && cities[lower])
            {
                if (upper == lower)
                {
                    ans += 1;
                    continue;
                }

                ans += 2;
                continue;
            }   
        }
        else if (upper >= start && lower >= 0)
        {
            if (cities[lower])
                ans += 1;
        }
        else if (upper < start && lower < 0)
        {
            if (cities[upper])
                ans += 1;
        }
    }
    cout << ans;
    return 0;
}