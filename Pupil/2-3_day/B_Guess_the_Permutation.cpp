#include <bits/stdc++.h>

using namespace std;

int n;

void columnUpdate(int column[], int solution[], int index);

void rowUpdate(int row[], int solution[], int index);

void finish(int solution[]);

int main()
{
    cin >> n;

    int table[n][n];

    int solution[n] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >>  table[i][j];
        }

        rowUpdate(table[i], solution, i);
    }

    for (int j = 0; j < n; j++)
    {
        int column[n];
        for (int i = 0; i < n; i++)
        {
            column[i] = table[i][j];
        }
        
        columnUpdate(column, solution, j);
    }
    
    finish(solution);
}

void columnUpdate(int column[], int solution[], int index)
{
    int howMany[n] = {0};

    for (int i = 0; i < n; i++)
    {
        howMany[column[i]] += 1;
        if (howMany[column[i]] > 1 && column[i] != 0)
        {
            solution[index] = column[i];
            for (int j = 0; j < n; j++)
            {
                if (column[j] < column[i] && column[j] != 0)
                {
                    solution[j] = column[j];
                }
            }
        }
    }

}

void rowUpdate(int row[], int solution[], int index)
{
    int howMany[n] = {0};

    for (int i = 0; i < n; i++)
    {
        howMany[row[i]] += 1;
        if (howMany[row[i]] > 1 && row[i] != 0)
        {
            solution[index] = row[i];
            for (int j = 0; j < n; j++)
            {
                if (row[j] < row[i] && row[j] != 0)
                {
                    solution[j] = row[j];
                }
            }
        }
    }
}

void finish(int solution[])
{
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (solution[i] == 0 && first)
        {
            solution[i] = n;
            first = false;
        }
        else if (solution[i] == 0 && !first)
        {
            solution[i] = n - 1;
        }

        cout << solution[i] << " ";
    }
}