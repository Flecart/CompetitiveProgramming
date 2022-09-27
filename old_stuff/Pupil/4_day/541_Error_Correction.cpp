#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        int start;
        cin >> start;
        if (start == 0)
        {
            break;
        }

        bool megaArr[start][start];

        short evenes[] = {0, 0};
        short coordinates[] = {0, 0};
        for (int i = 0; i < start; i++)
        {
            bool isEven = true;
            for (int j = 0; j < start; j++)
            {
                cin >> megaArr[i][j];
                isEven ^= megaArr[i][j];
            }
            
            if (!isEven)
            {
                evenes[0] += 1;
                coordinates[0] = i + 1;
            }
        }

        for (int j = 0; j < start; j++)
        {
            bool isEven = true;

            for (int i = 0; i < start; i++)
            {
                isEven ^= megaArr[i][j];            
            }

            if (!isEven)
            {
                evenes[1] += 1;
                coordinates[1] = j + 1;
            }
            
        }

        if (evenes[0] == 0 && evenes[1] == 0)
        {
            cout << "OK\n";
            continue;
        }
        else if (evenes[0] > 1 || evenes[1] > 1)
        {
            cout << "Corrupt\n";
            continue;
        }
        
        printf("Change bit (%d,%d)\n", coordinates[0], coordinates[1]);
        
        
    }
    return 0;
}