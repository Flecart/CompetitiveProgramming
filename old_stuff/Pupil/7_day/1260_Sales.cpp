#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main()
{
    int start;
    cin >> start;
    while (start--)
    {
        int boh;
        scanf("%d\n", &boh);
        int arr[boh];

        for (int i = 0; i < boh; i++)
        {
            cin >> arr[i];
        }

        int ans = 0;
        for (int i = boh - 1; i >= 0; i--)
        {   
            for (int j = i - 1; j >= 0; j--)
            {
                if (arr[i] >= arr[j])
                    ans += 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}