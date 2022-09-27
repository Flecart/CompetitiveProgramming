#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    while(cin >> start)
    {

        int corners = pow(2, start);
        
        char values[corners];
        int potencies[corners];
        for (int i = 0; i < corners; i++)
        {
            int temp;
            cin >> temp;
            values[i] = temp;
        }

        for (int i = 0; i < corners; i++)
        {
            int tempMax = 0;
            bitset<16> this_corner(i);
            // cout << this_corner.to_string() << endl;
            for (int i = 0; i < start; i++)
            {
                bitset<16> neighbour = this_corner;
                neighbour[i] = neighbour[i] ^ 1;

                int addThis = values[neighbour.to_ulong()];
                if (addThis < 0)
                    addThis += 256;
                tempMax += addThis;
                // cout << neighbour.to_ulong() << endl; 
            }

            potencies[i] = tempMax;
        }

        int maxValue = 0;
        for (int i = 0; i < corners; i++)
        {
            bitset<16> this_corner(i);
            for (int i = 0; i < start; i++)
            {
                bitset<16> neighbour = this_corner;
                neighbour[i] = neighbour[i] ^ 1;

                maxValue = max(potencies[this_corner.to_ulong()] + potencies[neighbour.to_ulong()], maxValue);
            }
        }

        cout << maxValue << '\n';
    }
    return 0;
}
