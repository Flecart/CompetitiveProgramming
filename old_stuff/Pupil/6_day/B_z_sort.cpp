#include <bits/stdc++.h>

using namespace std;

int main()
{
    int start;
    cin >> start;

    int arr[start];
    for (int i = 0; i < start; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + sizeof(arr) / sizeof(int));


    int low = 0, high = start - 1;

    if (start & 1)
    {
        while (low != high)
        {
            cout << arr[low++] << " ";
            cout << arr[high--] << " ";
        }
        cout << arr[low++] << " ";
        return 0;
    }
    while (low < high)
    {
        cout << arr[low++] << " ";
        cout << arr[high--] << " ";
    }

    // if (start & 1)
    // {
    //     for (int i = 0, j = start - 2; i < start || j > - 1;i += 2,j -= 2)
    //     {
            
    //         if (j > -1)
    //             cout << arr[j] << " ";

    //         if (i < start)
    //             cout << arr[i] << " ";
            
    //     }
    //     return 0;
    // }

    // for (int i = 0, j = start - 1; i < start && j > - 1;i += 2,j -= 2)
    // {
    //     cout << arr[j] << " " << arr[i] << " ";
    // }
       

    // return 0;
}