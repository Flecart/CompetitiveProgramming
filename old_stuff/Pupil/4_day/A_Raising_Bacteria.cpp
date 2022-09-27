#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    int ans = 0;
    while(start > 0)
    {
        // bitset<32> temp(start);
        // cout << temp.to_string() << endl;
        if (start & 1)
        {
            ans += 1;
        }
        start >>= 1;
    }

    cout << ans;

    return 0;
}