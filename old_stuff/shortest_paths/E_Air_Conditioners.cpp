#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define N_MAX (int)3e5 + 1
ll a[N_MAX];
int n, k;

// Al massimo ogni lastra è contata due volte, che succede quando due propagation
// Si incontrano fra di loro, migliore rispetto a O(n^n) della naive solution


int main()
{
    int cases;
    cin >> cases;
    while (cases--) 
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            a[i] = INT_MAX;
        }

        int positions[k];
        for (int i = 0; i < k; i++)
        {
            cin >> positions[i];
        }

        for (int i = 0; i < k; i++)
        {
            int tmp;
            cin >> tmp;
            a[positions[i] - 1] = tmp;
        }

        ll p = INT_MAX;

        vector<long long> L(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            p = min(p + 1, a[i]);
            L[i] = p;
        }
        
        p = INT_MAX;
        vector<long long> R(n, INT_MAX);
        for (int i = n; i >= 0; i--)
        {
            p = min(p + 1, a[i]);
            R[i] = p;
        }

        for (int i = 0; i < n; i++)
        {
            cout << min(L[i], R[i]) << " ";
        }
        cout << "\n";
    }
}

int naiveSolution()
{
    int cases;
    cin >> cases;
    while(cases--)
    {
        int n, k;
        cin >> n >> k;
        int a[k], t[k];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> t[i];
        }
        
        // This is the main part of this solution
        // Im looping over everysingle tile, for every single tile
        // I'm computing the minimum possible Value
        for (int i = 0; i < n; i++)
        {
            int min = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                int curr = t[j] + abs(a[j] - (i + 1));
                if (min > curr) min = curr;
            }
            
            printf("%d ", min);
        }
    }

    return 0;
}