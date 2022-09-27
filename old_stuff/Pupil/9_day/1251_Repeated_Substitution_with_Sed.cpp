#include <bits/stdc++.h>

using namespace std;
#define ll long long

string target;
int ans;
int tries, targetLen;

string possibilities[10][2];

string sed(string main, string a, string b)
{
    int len = main.length() - a.length() + 1;
    int i = 0;
    while(i < len)
    {
        string subs = main.substr(i, a.length());
        if (subs.compare(a) == 0)
        {
            main.erase(i, a.length());
            main.insert(i, b);

            i += b.length();
            len = main.length() - a.length() + 1;
            continue;
        }

        i++;
    }
    
    return main;
}

void search(string current, int steps)
{
    if (current.compare(target) == 0)
    {
        ans = min(ans, steps);
        return;
    }

    for (int i = 0; i < tries; i++)
    {
        string newString = sed(current, possibilities[i][0], possibilities[i][1]);
        int l = newString.length();
        if (newString.compare(current) == 0 || l > targetLen || l == 0)
            continue;
        search(newString, steps + 1);
    }
    
}

int main()
{
    // cout << sed("aaaa", "a", "bb");
    while (cin >> tries)
    {
        if (tries == 0)
            break;
        ans = INT_MAX;
        
        for (int i = 0; i < tries; i++)
        {
            cin >> possibilities[i][0] >> possibilities[i][1];
            if (possibilities[i][0].compare(possibilities[i][1]) == 0)
            {
                i--;
                tries--;
            }
        }

        string begin;
        cin >> begin >> target;
        targetLen = target.length();
        search(begin, 0);

        if (ans == INT_MAX)
            ans = -1;
        cout << ans << '\n';
    }
    
    

    return 0;
}