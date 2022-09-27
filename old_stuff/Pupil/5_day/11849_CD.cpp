#include <bits/stdc++.h>

using namespace std;

int main()
{
    int jack, jill;
    while (true)
    {

        int ans = 0;
        cin >> jack >> jill;

        if (jack == 0 && jill == 0)
            break;

        set<int> jackOwned;

        while (jack--)
        {
            int tmp;
            cin >> tmp;
            jackOwned.insert(tmp);
        }

        while (jill--)
        {
            int tmp;
            cin >> tmp;

            if (jackOwned.find(tmp) != jackOwned.end())
            {
                ans += 1;
            }
        }

        cout << ans << '\n';
        
        
    }
    


    return 0;
}