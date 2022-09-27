#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    while (start--)
    {
        int cases;
        cin >> cases;

        int arr[cases];
        for (int i = 0; i < cases; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;

        for (int i = 0; i < cases; i++)
        {
            for (int j = i + 1; j < cases; j++)
            {
                if (arr[i] > arr[j])
                    ans += 1;
            }
        }

        if (ans % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    

    return 0;
}