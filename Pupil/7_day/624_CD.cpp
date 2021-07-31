#include <bits/stdc++.h>

using namespace std;
#define ll long long

int curr[20] = {0}, solution[20] = {0};
int space, currentMax = 0;

void backtrack(int index, int sum, queue<int> toTry)
{
    if (sum > currentMax && sum <= space)
    {
        currentMax = sum;
        for (int i = 0; i < 20; i++)
        {
            if (i < index)
                solution[i] = curr[i];
            else
                solution[i] = 0;
        }
    }
    if (sum > space || toTry.empty())
        return;

    while(!toTry.empty())
    {
        curr[index] = toTry.front();
        toTry.pop();
        backtrack(index + 1, sum + curr[index], toTry);
    }
}

int main()
{
    while (cin >> space)
    {
        currentMax = 0;

        int track;
        cin >> track;
        queue<int> toTry;
        if (track == 0 || space == 0)
        {
            cout << "sum:0\n";
            continue;
        }

        for (int i = 0; i < track; i++)
        {
            int tmp;
            cin >> tmp;
            toTry.push(tmp);
        }

        backtrack(0, 0, toTry);

        int i = 0;
        while(solution[i] > 0 && i < 20)
        {
            cout << solution[i] << " ";
            i += 1;
        }
        cout << "sum:" << currentMax << '\n';
    }

    return 0;
}