#include <bits/stdc++.h>

using namespace std;

int start;

int main()
{
    cin >> start;

    char myChar[start + 1] = {0x31};
    cin.get(myChar[0]); // escape
    myChar[start] = '\0';

    for (int i = 0; i < start; i++)
    {
        cin.get(myChar[i]);
        if (myChar[i] != myChar[max(0, i - 1)])
        {
            start -= 2;
            myChar[start] = '\0';
            i -= 2;
        }
        // cout << myChar << endl;
    }

    cout << start;
    
    // cin.get(lastChar);
    // cin.get(lastChar);
    // // cout << lastChar << " ciaoaoidoiavcj";
    // start -= 1;
    // int ans = 0;
    // while(start--)
    // {
    //     cin.get(myChar);
    //     cout << myChar << ' ' << lastChar << ' ' << secondLastChar << '\n';

    //     if (myChar == lastChar)
    //     {
    //         ans += 1;
    //         char temp = lastChar;
    //         lastChar = myChar;
    //         secondLastChar = temp;
    //     }
    //     else
    //     {
    //         ans -= 1;
    //         lastChar = secondLastChar;
    //     }
    // }

    // cout << ans;


    return 0;
}