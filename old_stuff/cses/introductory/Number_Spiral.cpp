// https://cses.fi/problemset/task/1071/
// i solved this in cases.
// i divided this problem in main cases (even if i later realised)
// they were not necessary. Anyway,
// 1. y == x
// 2. y > x
// 3. y < x  
// And for each case i watched what the table was doing and created taht equation
// i notice now that i could just have swapped them

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;
    while (n-- ) {
        int y,x;
        scanf("%d %d", &y, &x);
        if (y == x) {
            printf("%lld\n", (ll) y * y - (y - 1));
        }
        else if (y > x) {
            if (y & 1) {
                printf("%lld\n", (ll)(y - 1) * (y - 1) + x);
            } else {
                printf("%lld\n", (ll)y * y - (x - 1));
            }
        } else {
            if (x & 1) {
                printf("%lld\n", (ll)x * x - (y - 1));
            } else {
                printf("%lld\n", (ll)(x - 1) * ( x - 1) + y);
            }
        }
    }

    return 0;
}