#include <bits/stdc++.h>

using namespace std;

int main()
{
    string word;
    set<string> dictionary;

    char currentChar;
    while (cin.get(currentChar))
    {
        if (!isalpha(currentChar))
        {
            if (!word.empty())
                dictionary.insert(word);
            word.clear();
            continue;
        }

        word += tolower(currentChar);
    }

    for (set<string>::iterator i = dictionary.begin(); i != dictionary.end(); i++)
    {
        cout << *i << '\n';
    }
    return 0;
}