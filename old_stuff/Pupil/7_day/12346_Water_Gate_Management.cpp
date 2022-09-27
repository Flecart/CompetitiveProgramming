#include <bits/stdc++.h>

using namespace std;
#define ll long long

int target, timeTaken;
int minimum;

void search(queue<pair<int, int>> toTry, int currentCost, int currentFlowRate)
{
    if (currentCost < minimum && currentFlowRate >= target)
    {
        minimum = currentCost;
    }
    else if (currentCost > minimum)
        return;

    // search solutions
    while (!toTry.empty())
    {
        pair<int, int> tmp = toTry.front();
        toTry.pop();
        search(toTry, currentCost + tmp.second, currentFlowRate + tmp.first * timeTaken);
    }
    return;
}

int main()
{
    int gatess;
    cin >> gatess;

    queue<pair<int, int>> toTry;
    while (gatess--)
    {
        int flowRate, cost;
        cin >> flowRate >> cost;

        toTry.push(make_pair(flowRate, cost));
    }

    int cases;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        minimum = INT_MAX;
        cin >> target >> timeTaken;

        cout << "Case " << i + 1 << ": ";

        search(toTry, 0, 0);

        if (minimum == INT_MAX)
            cout << "IMPOSSIBLE\n";
        else
            cout << minimum << "\n";
    }
    
    
    return 0;
}