#include <bits/stdc++.h>

using namespace std;

#define CURRENT 500

bool board[CURRENT][CURRENT];

int main()
{
    
    
    while (true)
    {   
        // reset the board
        for (int i = 0; i < CURRENT; i++)
        {
            for (int j = 0; j < CURRENT; j++)
            {
                board[i][j] = false;
            }
            
        }
        int width, height, n;
        cin >> width >> height >> n;

        if (height == 0 && width == 0 && n == 0)
        {
            break;
        }

        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                board[i][j] = true;
            }
        }

        while (n--)
        {
            int x1, y1 ,x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 > x2)
                swap(x1, x2);
            
            if (y1 > y2)
                swap(y1, y2);

            for (int i = x1 - 1; i < x2; i++)
            {
                for (int j = y1 - 1; j < y2; j++)
                {
                    board[i][j] = false;
                }
                
            }
        }

        int ans = 0;
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                if (board[i][j])
                    ans += 1;
            }
            
        }

        if (ans == 0)
            cout << "There is no empty spots.\n";
        else if (ans == 1)
            cout << "There is one empty spot.\n";
        else
            cout << "There are " << ans << " empty spots.\n";
    }
    return 0;
}