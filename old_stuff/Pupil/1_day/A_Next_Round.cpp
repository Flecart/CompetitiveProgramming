#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int k;
    int lastValue;
    int ans = 0;
    cin >> i;
    cin >> k;

    while(k--)
    {
        cin >> lastValue;
        if (lastValue == 0)
        {
            cout << ans;
            return 0;
        }
        i -= 1;
        ans += 1;
    }

    while(i--)
    {
        int value;
        cin >> value;

        if (value == lastValue)
        {
            ans += 1;
        }    
    }

    cout << ans;
    return 0;
}