#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    cin >> i;

    unsigned short firstValue = UINT16_MAX;
    unsigned short secondValue = UINT16_MAX;;
    bool inverted = false;
    while (i--)
    {
        cin >> firstValue;

        if (firstValue > secondValue)
        {
            inverted = true;
        }

        cin >> secondValue;

        if (firstValue != secondValue)
        {
            cout << "rated";
            return 0;
        }
    }

    if (inverted)
    {
        cout << "unrated";
        return 0;
    }

    cout << "maybe";
    return 0;
}