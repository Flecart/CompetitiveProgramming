#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define UPPER ((ll)1e18 + 1)

ll couples[5000] = {0};
ll x, y, l, r;

int cur = 0;

ll mult(ll first, ll second)
{
    ll div = UPPER /second;
    // cout << UPPER / second << " " << UPPER << endl;
    if (first > div)
    {
        return UPPER;
    }

    return first * second;
}

void generate()
{
    for (ll i = 1; i <= r; i = mult(x, i))
    {
        for (ll j = 1; j <= r; j = mult(y, j))
        {
            ll ans = i + j;

            if (ans > r)
                break;

            if (ans >= l)
            {
                couples[cur] = (ans);
                cur += 1;
            }
        }
        
    }
    
}

int main()
{
    // cout << UPPER << endl;
    cin >> x >> y >> l >> r;
    couples[cur] = l - 1;
    cur++;
    couples[cur] = r + 1;
    cur++;
    generate();
    sort(couples, couples + cur);
    ll ans = 0;

    int i = 0;
    for (int it = 0; it < cur - 1; it++)
    {
        i += 1;
        // cout << couples[it] << " \n";
        ans = max(ans, couples[1 + it] - couples[it] - 1);
    }

    // cout << i << endl;

    cout << ans;
}