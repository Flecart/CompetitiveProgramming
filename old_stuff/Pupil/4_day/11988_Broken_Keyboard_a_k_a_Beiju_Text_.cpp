#include <bits/stdc++.h>

using namespace std;

int main()
{   
    while(true)
    {
        list<char> sentence;
        list<char>::iterator it = sentence.begin();

        bool isEnd = true;
        bool isNew = false;
        char character = '\0';

        while(cin.get(character))
        {   
            // cout << (int) character << '\n';
            if (character == '\n')
                break;
            


            if (character == '[')
            {
                isEnd = false;
                isNew = true;
                continue;
            }
            else if (character == ']')
            {
                isEnd = true;
                continue;
            }

            if (isEnd)
            {
                sentence.push_back(character);
                continue;
            }
        
            if (isNew)
            {

                // sentence.push_front(character);
                it = sentence.begin();
                sentence.insert(it, character);
                isNew = false;
                continue;
            }
            sentence.insert(it, character);
        }

        // cout << (int) character <<  "fromhere" << '\n';
        if (character == '\0')
        {
            // cout << "executing";
            return 0;
        }

        for (list<char>::iterator i = sentence.begin(); i != sentence.end(); i++)
        {
            cout << *i;
        }
        cout << '\n';

        // return 0;
    }
    
    return 0;
}