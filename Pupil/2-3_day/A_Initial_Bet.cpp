#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum = 0;
    int temp;
    for (int i = 0; i < 5; i++)
    {
        cin >> temp;
        sum += temp;
    }

    if (sum % 5 == 0 && sum != 0)
    {
        cout << sum / 5;
    }
    else
    {
        cout << -1;
    }
    

    // do stuff

    return 0;
}