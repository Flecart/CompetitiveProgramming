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


/*
MINIMIZING COINS:
The most important thing to notice for this problem is that we have limited
amount of coins to check for each possible sum! (only 100) so its maximum
time of 100n (check 100 possible coins for each number under it)
(more precisely O(xn) where x is number of coins.)
*/

ll memo[(int) 10e6 + 1]{0};

ll solve(int arr[], int n, int x) {
    if (x <= 0) return inf;
    if (memo[x] > 0) return memo[x];
    ll mininum = inf;
    for (int i = 0; i < n; i++) {
        mininum = min(mininum, solve(arr, n, x - arr[i]));
    }
    return memo[x] = mininum + 1;
}

int main()
{
    IOS;
    prepare(n); prepare(x);
    int arr[n];
    seea(arr, 0, n);
    for (int i = 0; i < n; i++) {
        memo[arr[i]] = 1;
    }

    ll solution = solve(arr, n, x);
    if (solution >= inf) cout << -1; 
    else cout << solve(arr, n, x);
    return 0;
}