#include <bits/stdc++.h>

using namespace std;

int main()
{
    short a, b, c;
    cin >> a >> b >> c;

    short ans = 0;
    for (int i = b; i <= c; i += b)
    {
        if (i % a == 0)
            ans += 1;
    }
    
    cout << ans;
    return 0;
}