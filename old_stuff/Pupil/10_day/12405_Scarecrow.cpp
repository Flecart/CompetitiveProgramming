#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int start;
    cin >> start;

    for (int hello = 0; hello < start; hello++)
    {   
        int len;
        cin >> len;
        
        bool scarec[len + 2] = {0};
        
        int ans = 0;
        char tmp;
        cin.get(tmp);
        for (int i = 0; i < len; i++)
        {
            cin.get(tmp);
            if (tmp == '.' && !scarec[i])
            {
                ans += 1;
                scarec[i] = 1;
                scarec[i + 1] = 1;
                scarec[i + 2] = 1;
            }
        }
        printf("Case %d: %d\n", hello + 1, ans);
    }
    
    return 0;
}