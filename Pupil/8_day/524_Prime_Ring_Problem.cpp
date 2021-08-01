#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool used[16];
int solution[16];
int n;

inline bool isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
            return false;
    }

    return true;
}

void solve(int curr)
{
    // see if still good
    if (!isPrime(solution[curr - 2] + solution[curr - 1]) && curr > 1)
        return;
    

    if (curr == n)
    {
        if (!isPrime(solution[curr - 1] + solution[0]))
            return;

        for (int i = 0; i < n; i++)
        {
            cout << solution[i];
            if (i != n - 1)
                cout << " ";
            else 
                cout << '\n';
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            solution[curr] = i + 1;
            solve(curr + 1);
            used[i] = false;
        }
    }
    
}

int main()
{
    int j = 0;
    int input[16];
    while (cin >> n)
    {
        input[j++] = n;
    }

    for (int i = 0; i < j; i++)
    {
        n = input[i]; // making solve work
        for (int i = 0; i < 17; i++)
        {
            used[i] = 0;
        }
        used[0] = 1;
        solution[0] = 1;

        cout << "Case " << i + 1 << ":\n";
        solve(1);

        if (j - 1 != i)
            cout << "\n";
    }
        


    return 0;
}