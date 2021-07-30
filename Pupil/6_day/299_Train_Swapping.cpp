#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    while (start--)
    {
        int size;
        cin >> size;

        int arr[size];

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];  
        }

        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                if (arr[i] > arr[j])
                    ans++;
            }
        }

        cout << "Optimal train swapping takes " << ans << " swaps.\n";
        
    }
    

    return 0;
}