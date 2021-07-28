#include <bits/stdc++.h>

using namespace std;

int main()
{
    string first;
    string seconde;
    cin >> first >> seconde;

    if (first.length() < seconde.length())
    {
        cout << seconde.length();
    }
    else if (first.length() > seconde.length())
    {
        cout << first.length();
    }
    else
    {
        bool isSame = true;

        for (int i = 0; i < first.length(); i++)
        {
            if (seconde[i] != first[i])
            {
                isSame = false;
                break;
            }
        }

        if (isSame)
            cout << -1;
        else
            cout << first.length();
        
    }

    
    // for (int i = 0; i < first.length() - seconde.length() + 1; i++)
    // {
    //     if (first[i] == seconde[0])
    //     {
    //         bool isContained = true;
    //         for (int j = 0; j < seconde.length(); j++)
    //         {
    //             int k = i + j;

    //             if (first[k] != seconde[j])
    //             {
    //                 isContained = false;
    //             }
    //         }

    //         if (isContained)
    //         {
    //             cout << -1;
    //             return 0;
    //         }
    //     }
    // }
    
    // cout << first.length();
    return 0;
}