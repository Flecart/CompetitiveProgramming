#include <bits/stdc++.h>

using namespace std;

bool check(bool have_it[])
{
    for (int i = 0; i < 26; i++)
    {
        if (!have_it[i])
        {
            return false;
        }
    }

    return true;
}

void update(bool have_it[], char caracter)
{
    int number = toupper(caracter) - 0x41;

    if (!have_it[number])
    {
        have_it[number] = true;
    }
}

int main()
{
    int i;
    cin >> i;

    string input;
    cin >> input;

    bool have_it[26] = { 0 };

    for (int j = 0; j < i; j++)
    {
        update(have_it, input[j]);
    }

    if (check(have_it))
    {
        cout << "YES";
        return 0;
    }

    cout << "NO";
    return 0;

}