#include <bits/stdc++.h>

using namespace std;

int main()
{
    string sentence;
    // while(cin >> sentence)
    // {
    //     cout << sentence << endl;
    // }
    getline(cin, sentence);

    char ans[sentence.length()];

    int j = 0;
    int lastChar = 0;
    for (int i = 0; i < sentence.length(); i++)
    {
        if (isalpha(sentence[i]))
        {
            ans[j] = sentence[i];
            j += 1;
            continue;
        }
        else if (sentence[i] == ' ')
        {
            if (isalpha(ans[j - 1]))
            {
                ans[j] = ' ';
                j += 1;
            }
        }
        else if (ispunct(sentence[i]))
        {
            if (ans[j - 1] == ' ')
                j -= 1;
            ans[j] = sentence[i];
            ans[j + 1] = ' ';
            j += 2;
        }
    }

    ans[j] = '\0';
    cout << ans;
}