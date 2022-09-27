#include <bits/stdc++.h>

using namespace std;

int *get_position()
{
    int i;
    int j;
    int value;

    for(i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cin >> value;
            if (value == 1)
            {
                static int ans[] = {i, j};
                return ans;
            } 
        }
    }
    return NULL;
}

int main()
{
    int *position = get_position();
    cout << abs(*position - 2) + abs(*(position + 1) - 2);
    // cout<<*(position + 1);
}