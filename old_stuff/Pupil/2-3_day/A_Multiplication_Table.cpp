#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    int ans = 0;
    int number;
    cin >> number;

    for (int i = 1; i <= sqrt(number); i++)
    {
        if (number % i == 0 && number / i <= start)
        {
            if (number / i == i)
            {
                ans += 1;
                continue;
            }
            ans += 2;
        }
    }

    cout << ans;
    return 0;
}