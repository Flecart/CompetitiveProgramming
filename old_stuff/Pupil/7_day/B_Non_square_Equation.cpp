#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n;


inline int equation(ll x)
{
    int ans = 0;

    int copy = x;
    while(x > 0)
    {
        ans += x % 10;
        x /= 10;
    }
    return copy * copy + ans * copy - n;
}

int main()
{
    cin >> n;

    ll ans = LONG_MAX;
    for (int i = 1; i <= 90; i++)
    {
        ll delta = i * i + 4 * n;
        ll square = sqrt(delta);

        if (square * square == delta && square - i > 0)
        {
            ll solution = (-i + square) / 2;

            if (equation(solution) == 0)
            {
                ans = min(ans, solution);
            }
        }
        else 
            continue;
    }
    
    if (ans == LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}