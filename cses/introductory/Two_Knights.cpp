// https://cses.fi/problemset/task/1072 
// First i get the total number of knights on the table.
// so i get the combinations of 2 for every single square of the table 
// which is i * i (square table).
// Then i have to subtract the possible attacks.
// An attack is possible iff i can place a 2x3 or 3x2 block 
// and for every block i can get 2 attacks, for example
// (x is a knight and . an empty block);
// x..
// ..x is an attack
// ..x
// x.. is another attack
// and this is the same for the vertical one.
// So i just calculate how many 2x3 and 3x2 tyles are there (which is the same because it's squared)
// and then multiply by 4 because for each tyle we said 2 attacks.'


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    scanf("%d", &n);
    printf("0\n");
    for (int i = 2; i <= n; i++)
    {
        printf("%lld\n", (ll) i * i * (i * i - 1) / 2 - (ll) 4 * (i - 1) * (i - 2));
    }
    

    return 0;
}