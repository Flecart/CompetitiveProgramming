#include <bits/stdc++.h>

using namespace std;

int N;

void solve()
{
    string highway;
    int distance = 0;

    // -N is usefull to prevent some bugs...
    int currentDrugstore;
    int lastDrugstore = -N;
    int currentFood;
    int lastFood = -N;

    cin >> highway;

    if (highway.find('Z') < highway.length())
    {
        cout << distance << "\n";
        return;
    }

    // Usefull to use for comparisons now
    distance = INT_MAX;
    for (int i = 0; i < highway.length(); i++)
    {
        if (highway[i] == 'R')
        {
            currentFood = i;
            int tempDist = currentFood - lastDrugstore;
            distance = min(tempDist, distance);
            lastFood = currentFood;

            continue;
        }
        else if (highway[i] == 'D')
        {
            currentDrugstore = i;
            int tempDist = currentDrugstore - lastFood;
            distance = min(tempDist, distance);
            lastDrugstore = currentDrugstore;

            continue;
        }
    }

    cout << distance << "\n";
    return;
}

int main()
{
    while (true)
    {
        cin >> N;
        if (N == 0)
        {
            return 0;
        }

        solve();
    }
}