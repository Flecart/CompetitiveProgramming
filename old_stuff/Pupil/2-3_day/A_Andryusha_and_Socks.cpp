#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    int maxNumber = 0;
    vector<int> table;
    cin >> start;
    start *= 2;
    while (start--)
    {
        int temp;
        cin >> temp;

        vector<int>::iterator position = find(table.begin(), table.end(), temp);
        if (position == table.end())
        {
            table.push_back(temp);
            maxNumber = max(maxNumber, (int) table.size());
        }
        else
        {
            table.erase(position);
        }
    }

    cout << maxNumber;
    

    return 0;
}