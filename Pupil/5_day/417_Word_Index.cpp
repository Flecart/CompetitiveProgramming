#include <bits/stdc++.h>

using namespace std;

map<string, int>  dict;

inline void generate()
{   
    queue<string> listOfWords;

    string tmp;

    for (int i = 'a'; i <= 'z'; i++)
    {
        tmp += (char) i;
        listOfWords.push(tmp);

        tmp.clear();
    }

    int begin = 1;
    // aka esce quando il queue è completo
    while (!listOfWords.empty())
    {
        tmp = listOfWords.front();
        // if (begin > 83670)
        //     cout << tmp << begin <<  endl;
        dict.insert(pair<string, int>(tmp, begin));
        begin += 1;

        int beginWithThis = (int)tmp.back() + 1;
        for (int i = beginWithThis; i <= 'z' && tmp.length() < 5; i++)
        {
            tmp += (char) (i);
            listOfWords.push(tmp);

            tmp = listOfWords.front();
        }

        listOfWords.pop();
    }
}

int main()
{
    generate();
    string input;

    while (cin >> input)
    {
        bool isValid = true;
        for (int i = 1; i < input.length(); i++)
        {
            if (input[i] < input[i - 1])
            {
                cout << 0 << '\n';
                isValid = false;
                break;
            }
        }
        if (isValid)
            cout << dict.at(input) << '\n';

    }
    
    

    return 0;
}