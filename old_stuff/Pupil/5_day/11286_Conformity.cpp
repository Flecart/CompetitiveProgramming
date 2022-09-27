#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (true)
    {
        int number;
        cin >> number;
        if (number == 0)
        {
            break;
        }
        map<long, int> popularity;
        while (number--)
        {
            long hash = 1; // questo hash è buggato, non è sempre uguale....
            int arr[5];
            for (int i = 0; i < 5; i++)
            {
                cin >> arr[i];
            }
            sort(arr, arr + sizeof(arr) / sizeof(int));
            for (int i = 0; i < 5; i++)
            {
                hash *= arr[i] * (i + 2);
            }
            
            popularity[hash] += 1;
        }

        int max_val = 0;
        for (auto i : popularity)
            max_val = max(i.second, max_val);

        int cnt = 0;
        for (auto i : popularity)
            if (max_val == i.second)
                cnt += 1;

        cout << max_val * cnt << '\n';

    }
    

    return 0;
}

// non so perché ancora non me lo accetta... forse è l'hash, ma ora dovrebbe essere sicuro!
// https://www.davidudelson.com/blog/2015/07/07/uva-11286-conformity/ qua per la soluzione altra