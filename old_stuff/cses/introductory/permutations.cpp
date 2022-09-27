// https://cses.fi/problemset/task/1070
// Just notice that in the case 3 and 2 there are no solution
// When in all other cases there are.
// So for all other cases i'm printing in a decreasing fashion the number
// e.g. 3 1 4 2.
// i cant print in incresing fashion because in the case n = 4
// there is only this kind of soluzion (1 3 2 4 doesn't work)
// and neither 4 2 3 1. So i just did a lot of trial and error
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    if (n == 3 || n == 2) {
        printf("NO SOLUTION\n");
        return 0;
    }
    
    for (int i = n - 1; i > 0; i -= 2)
    {
        printf("%d ", i);
    }
    for (int i = n; i > 0; i -= 2)
    {
        printf("%d ", i);
    }

    printf("\n");
    
    
    return 0;
}