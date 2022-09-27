#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    while(start--)
    {
        map<string, string> dict;
        map<string, string> secondDict;

        string key;
        string value;
        char tmp;
        bool isKey = true;
        do
        {
            cin.get(tmp);
            if (tmp == '{' || tmp == '\n')
                continue;

            else if (tmp == ':')
            {
                isKey = false;
                continue;
            }
            else if (tmp == ',' || tmp == '}')
            {
                dict.insert(pair<string, string>(key, value));
                key.clear();
                value.clear();
                isKey = true;
                continue;
            }

            if (isKey)
            {
                key += tmp;
            }
            else
            {
                value += tmp;
            }
        } while (tmp != '}');
        
        set<string> added;
        set<string> removed;
        set<string> valueChanged;
        do
        {
            cin.get(tmp);
            if (tmp == '{' || tmp == '\n')
                continue;

            else if (tmp == ':')
            {
                isKey ^= 1;
                continue;
            }
            else if (tmp == ','|| tmp == '}')
            {
                secondDict.insert(pair<string, string>(key, value));

                if (dict.find(key) == dict.end())
                {
                    if (!key.empty())
                        added.insert(key);
                }
                else
                {
                    if (dict.at(key) != secondDict.at(key))
                    {
                        if (!key.empty())
                            valueChanged.insert(key);
                    }
                }

                key.clear();
                value.clear();
                isKey ^= 1;
                continue;
            }

            if (isKey)
            {
                key += tmp;
            }
            else
            {
                value += tmp;
            }
        } while (tmp != '}');
        
        for (const auto &pair : dict)
        {
            if (secondDict.find(pair.first) == secondDict.end())
            {
                if (!pair.first.empty())
                    removed.insert(pair.first);
            }
        }

        bool hasChanged = false;
        if (!added.empty())
        {
            cout << '+';

            auto last = added.end();
            last--;
            for (auto it = added.begin(); it != added.end(); it++)
            {
                cout << *it;

                if (it == last)
                    continue;

                cout << ",";
            }
            cout << '\n';
            hasChanged = true;
        }


        if (!removed.empty())
        {
            cout << '-';
            
            auto last = removed.end();
            last--;
            for (auto it = removed.begin(); it != removed.end(); it++)
            {
                cout << *it;

                if (it == last)
                    continue;

                cout << ",";
            }
            cout << '\n';
            // cout << "I am not empty!";
            hasChanged = true;
        }

        if (!valueChanged.empty())
        {
            cout << '*';

            auto last = valueChanged.end();
            last--;
            for (auto it = valueChanged.begin(); it != valueChanged.end(); it++)
            {
                cout << *it;

                if (it == last)
                    continue;

                cout << ",";
            }
            cout << '\n';

            hasChanged = true;
        }

        if (!hasChanged)
        {
            cout << "No changes\n";
        }
        cout << "\n";
        
    }

    return 0;
}