#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int s, n;
    cin >> s >> n;

    pair<int, int> dragons[n];

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        dragons[i] = make_pair(a, b);
    }

    sort(dragons, dragons + n);
    
    bool win = true;
    for (int i = 0; i < n; i++)
    {
        if (s <= dragons[i].first)
        {
            win = false;
            break;
        }

        s += dragons[i].second;
    }
    
    if (win)
        printf("YES");
    else
        printf("NO");

    return 0;
}