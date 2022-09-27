#include <bits/stdc++.h>

using namespace std;

#define WHAT 220


bool possible(int x, int y);
int sum(int x, int y);

int main()
{
    int x, y;
    cin >> x >> y;

    bool isCielTurn = true;

    while(possible(x, y))
    {
        if (isCielTurn)
        {
            int tolte = x - max(0, x - 2);
            x -= tolte;
            int needed = WHAT - tolte * 100;

            y -= needed / 10;
        }
        else
        {
            int tolte;
            int possibili[] = {22, 12, 2};
            for (int i = 0; i < 3; i++)
            {
                if (possibili[i] <= y)
                {
                    tolte = possibili[i];
                    break;
                }
            }
            y -= tolte;

            int needed = WHAT - tolte * 10;
            x -= needed / 100;

        }

        // cout << x << ' ' << y << ' ' << isCielTurn << '\n';

        isCielTurn = isCielTurn ? false : true;
    }

    if (isCielTurn)
        cout << "Hanako";
    else
        cout << "Ciel";

    return 0;
}

bool possible(int x, int y)
{

    if (sum(x, y) < WHAT)
        return false;

    if (y < 2)
        return false;

    return true;
    
}

int sum(int x, int y)
{
    
    return x * 100 + y * 10;
}