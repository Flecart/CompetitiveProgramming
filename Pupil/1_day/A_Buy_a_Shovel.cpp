#include <bits/stdc++.h>

using namespace std;

int main()
{
    int price;
    int j;
    cin >> price;
    cin >> j;
    price %= 10;

    for (int i = 1; i < 11; i++)
    {   
        int currentRem = (price * i) % 10;
        if (currentRem == 0 || currentRem == j)
        {
            cout << i;
            return 0;
        }
    }
}