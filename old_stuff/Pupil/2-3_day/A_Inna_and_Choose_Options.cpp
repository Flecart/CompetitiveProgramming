#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number;
    int divisors[] = {1, 2, 3, 4, 6, 12};

    cin >> number;


    while(number--)
    {
        string input;
        cin >> input;

        int ans = 0;
        int answer[6] = {0};

        for (short i = 0; i < 6; i++)
        {
            int row = divisors[i];
            int columns = 12 / row;

            bool isGood = false;
            for (int i = 0; i < columns; i++)
            {
                bool stillEqual = true;
                for (int j = i; j < 12; j += columns)
                {
                    if (input[j] != 'X')
                    {
                        stillEqual = false;
                    }
                }

                if (stillEqual)
                {
                    isGood = true;
                    break;
                }
            }
            if (isGood)
            {
                answer[i] = row;
                ans += 1;
            }
        }
        
        cout << ans << " ";

        for (short i = 0; i < 6; i++)
        {
            if (answer[i] != 0)
            {
                cout  << answer[i] << "x" << 12 / answer[i] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}