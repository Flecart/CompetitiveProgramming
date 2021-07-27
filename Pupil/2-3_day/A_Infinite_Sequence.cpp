#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    int preferite;
    int diff;
    cin >> start >> preferite >> diff;

    if ((preferite < start && diff > 0) || (preferite > start && diff < 0))
    {
        cout << "NO";
        return 0;
    }

    if (diff == 0)
    {
        if (start == preferite)
            cout << "YES";
        else
            cout << "NO";

        return 0;
    }

    preferite -= start;
    if (preferite % diff == 0)
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;
}