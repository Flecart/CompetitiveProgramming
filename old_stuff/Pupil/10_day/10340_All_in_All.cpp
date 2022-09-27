#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    string s, t;
    while (cin >> s)
    {
        cin >> t;

        int sIndex = 0;
        bool coded = false;
        for (int i = 0; i < t.length(); i++)
        {
            if (t[i] == s[sIndex])
            {
                sIndex += 1;
                if (sIndex == s.length())
                {
                    coded = true;
                    break;
                }
            }
        }

        if (coded)
            cout << "Yes\n";
        else
            cout << "No\n";
            
    }
    

    return 0;
}