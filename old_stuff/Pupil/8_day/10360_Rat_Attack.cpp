#include <bits/stdc++.h>

using namespace std;
#define ll long long

#define UP 1025

int grid[UP][UP] = {0};

int main()
{
    int start;
    
    cin >> start;
    while (start--)
    {
        int d, rats;
        
        cin >> d >> rats;
        int ans[3] = {0};
        ans[2] = INT_MIN;
        while (rats--)
        {
            int x, y, size;
            cin >> x >> y >> size;
            for (int i = max(0, x - d); i < min(x + d, UP - 1) + 1; i++)
            {
                for (int j = max(0, y - d); j < min(y + d, UP - 1) + 1; j++)
                {
                    grid[i][j] += size;
                }
            }
            
        }       

        for (int i = 0; i < UP; i++)
        {
            for (int j = 0; j < UP; j++)
            {
                if (grid[i][j] > ans[2])
                {
                    ans[0] = i;
                    ans[1] = j;
                    ans[2] = grid[i][j];
                }
                grid[i][j] = 0;
            }
        }
        
        cout << ans[0] << " " << ans[1] << " " << ans[2] << '\n';
        
    }
    return 0;
}