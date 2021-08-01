#include <bits/stdc++.h>



using namespace std;
#define ll long long

#define TARGET 23
#define n 5

bool ans = false;


bool searched[6] = {0};

// avevo na soluzione prima che invece di usare DFS come qua
// cercava le operazioni giuste per ogni permutazione possibile
// ma non funzionava...

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

    for (int i = 0; i < n; i++)
    {
        if (!searched[i])
        {
            searched[i] = true;

            if (curr == 0)
            {
                search(values, curr + 1, values[i]);
            }
            else
            {
                search(values, curr + 1, sum + values[i]);
                search(values, curr + 1, sum - values[i]);
                search(values, curr + 1, sum * values[i]);
            }

            searched[i] = false;
        }
    }
    

    
    return;
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

        search(values, 0 , 0);

        if (ans)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}