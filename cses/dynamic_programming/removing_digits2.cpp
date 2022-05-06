#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pii> vii;


//----------CONSTANTS----------
const int inf = INT_MAX;
const ll linf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

/* REMOVING DIGITS:
The only thing that deviates from standard dinamic programming is the case
when the digit is 0, in that case the recursion never stops, i just skip this.

The thing to notice is that the subproblem is always n - digit_chosen, this is 
what i'm doing
*/

int get_max(int n) {
    int mmax = 0;
    while (n) {
        mmax = max(mmax, n % 10);
        n /= 10;
    }
    return mmax;
}

int solve(int target) {
    int sol = 0;
    while (target) {
        target -= get_max(target);
        sol++;
    }
    return sol;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    cout << solve(n);
    return 0;
}