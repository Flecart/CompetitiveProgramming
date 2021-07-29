#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word;
    set<string> dictionary;

    char currentChar;
    while (cin.get(currentChar))
    {
        if (!isalpha(currentChar) && currentChar != '-')
        {
            if (!word.empty())
                dictionary.insert(word);
            word.clear();
            continue;
        }
        else if (currentChar == '-')
        {
            cin.get(currentChar); // escape

            if (currentChar != '\n')
            {
                word += '-';
                word += tolower(currentChar);
            }
            continue;
        }

        word += tolower(currentChar);
    }

    for (auto i : dictionary)
    {
        cout << i << '\n';
    }
    return 0;
}