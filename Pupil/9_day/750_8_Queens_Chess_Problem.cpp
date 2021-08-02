#include <bits/stdc++.h>

using namespace std;
#define ll long long


int row[8];
int firstCol, firstRow;

int currAns;

bool canPlace(int r, int c)
{   
    if (c == firstRow || abs(firstRow - c) == abs(firstCol - r))
        return false;
    for (int i = 0; i < r; i++)
    {
        if (row[i] == c || (abs(row[i] - c) == abs(i - r)))
            return false;
    }
    return true; 
}

void search(int n)
{
    if (n == firstCol)
    {
        search(n + 1);
        return;
    }

    if (n == 8)
    {
        cout << setw(2) << currAns << "      ";
        currAns += 1;

        for (int i = 0; i < 8; i++)
        {
            cout << row[i] + 1;
            if (i != 7)
                cout << " ";
            else
                cout << "\n";
        }
    }

    for (int i = 0; i < 8; i++)
    {
        if (canPlace(n, i))
        {
            row[n] = i;
            search(n + 1);
        }
    }
    
}

int main()
{
    int start;
    cin >> start;

    while (start--)
    {
        // reinitialize globas
        currAns = 1;
        for (int i = 0; i < 8; i++)
        {
            row[i] = 0;
        }

        cin >> firstRow >> firstCol;
        firstCol--;
        firstRow--;
        row[firstCol] = firstRow;
        cout << "SOLN       COLUMN\n";
        cout << " #      1 2 3 4 5 6 7 8\n\n";
        search(0);
        if (start != 0)
            cout << '\n';
    }
    return 0;
}