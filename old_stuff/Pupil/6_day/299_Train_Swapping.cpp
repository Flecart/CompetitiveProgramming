#include <bits/stdc++.h>

using namespace std;

void fill(int copy[], int begin, int end, int arr[])
{
    int n = end - begin + 1;
    for (int i = 0; i < n; i++)
    {
        copy[i] = arr[i + begin];
    }
    
}

int merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1, n2 = right - mid;

    int first[n1], second[n2];

    fill(first, left, mid, arr);
    fill(second, mid + 1, right, arr);

    int swaps = 0;

    for (int i = left, j = 0, k = 0; i < n1 + n2 + left; i++)
    {
        if (j < n1 && k < n2)
        {
            if (first[j] <= second[k])
            {
                arr[i] = first[j++];
            }
            else
            {
                arr[i] = second[k++];
                swaps += n1 - j;
            }
        }
        else if (j >= n1 && k < n2)
        {
            arr[i] = second[k++];
        }
        else
        {
            arr[i] = first[j++];
        }
    }
    return swaps;
}

int mergeSort(int arr[], int left, int right)
{
    
    if (left >= right)
        return 0;
    
    int mid = (right + left) / 2;

    int ans = 0;

    ans += mergeSort(arr, left, mid);
    ans += mergeSort(arr, mid + 1, right);

    ans += merge(arr, left, mid, right);
    return ans;
}

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
        ans = mergeSort(arr, 0, size - 1);

        // for (int i = 0; i < size; i++)
        // {
        //     cout << arr[i];
        // }
        
        // for (int i = 0; i < size; i++)
        // {
        //     for (int j = i; j < size; j++)
        //     {
        //         if (arr[i] > arr[j])
        //             ans++;
        //     }
        // }

        cout << "Optimal train swapping takes " << ans << " swaps.\n";
        
    }
    return 0;
}