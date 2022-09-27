#include <bits/stdc++.h>

using namespace std;

bool check(short int year)
{
    vector<short> digits;
    while(year)
    {
        short current = year % 10;
        digits.push_back(current);
        year /= 10;
    }
        

    for (unsigned short i = 0; i < digits.size() - 1; i++)
    {
        for (unsigned short j = i + 1; j < digits.size(); j++)
        {
            if (digits[i] == digits[j])
                return false;
        }    
    }
    return true;
}

int main()
{
    short int start;
    cin >> start;

    while(start++)
    {   
        if (check(start))
        {
            cout << start;
            return 0;
        }
    }
}