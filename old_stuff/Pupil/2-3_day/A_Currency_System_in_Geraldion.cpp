#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    int values[start];
    int n = sizeof(values) / sizeof(values[0]);
    while(start--)
    {
        cin >> values[start];
    }

    sort(values, values + n);

    if (values[0] > 1)
        cout << 1;
    else
        cout << -1;
    return 0;
}