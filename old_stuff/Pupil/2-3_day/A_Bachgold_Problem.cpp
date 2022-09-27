#include <bits/stdc++.h>

using namespace std;



int main()
{
    int start;
    cin >> start;

    int ans;
    if (start & 1 == 1)
    {
        ans = (start - 3) / 2 + 1;
        cout << ans << "\n";
        for (int i = 0; i < ans - 1; i++)
        {
            cout << 2 << ' ';
        }
        cout << 3;
        return 0;
    }

    ans = start / 2;
    cout << ans << '\n';

    for (int i = 0; i < ans; i++)
    {
        cout << 2 << " ";
    }
    
    
    return 0;
}