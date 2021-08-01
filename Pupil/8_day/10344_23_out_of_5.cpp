#include <bits/stdc++.h>

/* 
This is a solution that passed every test but couldnt pass the UVA submission
Somehow i got WA... I don know what i did wrong.
*/

using namespace std;
#define ll long long

#define TARGET 23
#define n 5

bool ans = false;



void search(vector<int> values, int curr, int sum)
{
    if (ans)
        return;

    if (curr == 5)
    {
        if (sum == TARGET)
            ans = true;
        return;
    }

    int tmp = values[curr];

    if (curr == 0)
    {
        search(values, curr + 1, tmp);
        return;
    }

    search(values, curr + 1, sum + tmp);
    search(values, curr + 1, sum - tmp);
    search(values, curr + 1, sum * tmp);

    return;
}

inline void permutate_search(vector<int> values)
{
    while (next_permutation(values.begin(), values.end()))
    {
        search(values, 0, 0);
    }
    
}

int main()
{
    
    while (true)
    {
        ans = false;
        bool end = true;

        vector<int> values;

        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            values.push_back(tmp);
            if (end && tmp != 0)
                end = false;
        }
        if (end)    
            break;

        sort(values.begin(), values.end());

        permutate_search(values);

        if (ans)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}