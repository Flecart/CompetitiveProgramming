#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if (x.first != y.first)
        return x.first < y.first; //return the one with smaller first element
    else
        return x.second > y.second; //if first element is equal then return the one with smaller second element
}

struct rigthMost
{
    int value;
    int index;
    int last;
};

int main()
{
    int len, n;
    while (true)
    {
        cin >> len >> n;
        if (len == 0 && n == 0)
            break;

        pair<int, int> intervals[n];
        for (int i = 0; i < n; i++)
        {
            int loc, range;
            cin >> loc >> range;
            intervals[i] = make_pair(max(0, loc - range), min(len, loc + range));
        }
        
        sort(intervals, intervals + n, cmp);

        int a = 0, count = 0, s = 0;

        while (a < len)
        {
            int maxi = a;
            while (s < n && intervals[s].first <= a)
            {
                maxi = max(intervals[s++].second, maxi);
            }

            if (maxi == a)  // not changed
                break;
            
            a = maxi;
            count += 1;
        }
        
        if (a < len)
            cout << -1 << '\n';
        else
            printf("%d\n", n - count);
    }
    

    return 0;
}