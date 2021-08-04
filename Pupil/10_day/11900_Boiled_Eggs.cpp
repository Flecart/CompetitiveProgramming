#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int start;
    cin >> start;
    for (int j = 0; j < start; j++)
    {
        int n, p, q;
        cin >> n >> p >> q;

        int egg;
        int ans = 0;
        int weight = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> egg;
            if (ans + 1 <= p && weight + egg <= q)
            {
                ans += 1;
                weight += egg;
            }
        }

        printf("Case %d: %d\n", j + 1, ans);
        
    }

    return 0;
}