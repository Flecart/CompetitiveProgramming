#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int rows;
        cin >> rows;
        if (rows == 0)
        {
            break;
        }

        int maxi = 0;
        int ans = 0;
        int numberX[rows] = {0};

        for (int j = 0; j < rows; j++)
        {
            char temp;
            for (int i = 0; i < 25; i++)
            {
                cin.get(temp);
                if (temp == 'X')
                    numberX[j] += 1;
            }

            cin.get(temp);

            maxi = max(maxi, numberX[j]);
        }

        for (int i = 0; i < rows; i++)
        {
            ans += maxi - numberX[i];
        }

        cout << ans << '\n';
    }

    return 0;
}