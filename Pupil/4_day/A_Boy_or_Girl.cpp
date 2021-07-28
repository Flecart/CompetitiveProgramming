#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input;
    cin >> input;

    bool alphabet[26] = {0};

    for (int i = 0; i < input.length(); i++)
    {
        alphabet[input[i] - 'a'] = true;
    }
    
    short sum = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i])
            sum += 1;
    }

    if (sum & 1)
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    

    return 0;
}