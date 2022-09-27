#include <bits/stdc++.h>

using namespace std;

void answer(long long sum , int mininum)
{
    if (sum % 2 == 0)
    {
        cout << sum;
        return;
    }
    cout << sum - mininum;
    return;
}


int main()
{
    int i;
    cin >> i;

    int mininum = INT_MAX;
    long long sum = 0;

    while (i--)
    {
        int input;
        cin >> input;
        mininum = input % 2 == 1 ? min(input, mininum) : mininum;

        sum += input;
    }

    answer(sum, mininum);
    return 0;
}