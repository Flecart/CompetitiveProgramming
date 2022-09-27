#include <bits/stdc++.h>

using namespace std;

int main()
{
    int target;
    int special, oneCost, multipleCost;
    cin >> target >> special >> oneCost >> multipleCost;

    if (multipleCost > oneCost * special)
    {
        cout << oneCost * target;
        return 0;
    }
    else if (multipleCost < oneCost)
    {
        int numberOfSpecials = ceil((float)target / special);

        cout << numberOfSpecials * multipleCost;
        return 0;
    }
    int numberOfSpecials; 
    if (special > target && target != 1)
        numberOfSpecials = 1;
    else
        numberOfSpecials = target / special;

    target = max(0, target - numberOfSpecials * special);

    cout << numberOfSpecials * multipleCost + target * oneCost;
    return 0;
}