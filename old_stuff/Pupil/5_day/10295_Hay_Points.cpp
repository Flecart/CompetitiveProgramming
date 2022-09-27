#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start, desc;
    cin >> start >> desc;

    map<string, int> dict;

    while (start--)
    {
        string role;
        int number;
        cin >> role >> number;

        dict.insert(make_pair(role, number));    
    }

    int ans = 0;
    while (desc--)
    {
        string word;
        while (true)
        {
            cin >> word;

            if (word.compare(".") == 0)
            {
                cout << ans << '\n';
                ans = 0;
                break;
            }
            
            if (dict.find(word) != dict.end())
            {
                ans += dict.at(word);
            }
        }
    }
    
    
    

    return 0;
}