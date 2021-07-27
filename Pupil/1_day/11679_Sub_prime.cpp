#include <bits/stdc++.h>

using namespace std;

#define NUMBER 3

int B, N;

bool check(int reserves[])
{
    for (int i = 0; i < B; i++)
    {
        if (reserves[i] < 0)
        {
            return false;
        }
    }
    
    return true;
}

void answer(int reserves[], int debts[][NUMBER])
{
    for (int i = 0; i < N; i++)
    {
        int debitor = debts[i][0] - 1;
        int creditor = debts[i][1] - 1;
        int quantity = debts[i][2];

        reserves[debitor] -= quantity;
        reserves[creditor] += quantity;
    }

    if (check(reserves))
    {
        cout << "S\n";
        return;
    }

    cout << "N\n";
    return;
}

int main()
{
    string input;

    while (true)
    {
        
        cin >> B;
        cin >> N;

        if (B == 0 && N == 0)
        {
            return 0;
        }

        int reserves[B];
        int debts[N][NUMBER];
        for (int i = 0; i < B; i++)
        {
            cin >> reserves[i];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < NUMBER; j++)
            {
                cin >> debts[i][j];
            }
        }
        answer(reserves, debts);
    } 
}