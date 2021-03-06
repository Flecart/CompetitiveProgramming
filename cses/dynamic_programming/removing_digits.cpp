#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pii> vii;

#define vc vector
#define pb push_back
#define F first
#define S second
#define nl cout<<'\n'
#define E cerr<<'\n'
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false)
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define cspace << ' ' <<
#ifndef FILE
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define prepare(x) int x; cin >>x;
#else 
#define seea(a,x,y) for(int i=x;i<y;i++){fin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; fin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; fin>>x; s.insert(x);}
#define prepare(x) int x; fin >> x;
#endif
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

int memo[(int)1e6 + 1]{0};

int solve(int target) {
    if (target <= 0) return 0; 
    if (memo[target] != 0) return memo[target];

    int best = inf;
    int n = target;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        if (digit == 0) continue;
        best = min(best, solve(target - digit));
    }
    return memo[target] = best + 1;
}

int main()
{
    IOS;
    prepare(n);
    cout << solve(n);
    return 0;
}