#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int start;
        cin >> start;

        if (start == 0)
        {
            break;
        }
        int arr[start];
        int max_value = 0;
        for (int i = 0; i < start; i++)
        {
            cin >> arr[i];

            max_value = max(max_value, arr[i]);            
        }

        int count[max_value] = {0};
        
        for (int i = 0; i < start; i++)
        {
            count[arr[i] - 1] += 1;
        }
        
        for (int i = 0; i < max_value; i++)
        { 
            while (count[i]--)
            {
                cout << i + 1;
                if (i == max_value - 1 && count[i] == 0)
                    break;

                cout << " ";
            }

            
        }

         cout << '\n';
            
        
    }
    

    return 0;
}