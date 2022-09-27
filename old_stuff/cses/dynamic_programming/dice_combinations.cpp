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

/* DICE COMBINATIONS: 
This is a classic dinamic programming problem (very much alike cutting ropes).
The main observation is that the solution of the general problem can be written
in terms of the same problem in terms of smaller input.
*/

inline ll mod(ll n, int p) {
    if (n < 0) return n + p;
    else return n % p;
}

ll solve(int n) {
    ll memo[6]{0};
    memo[0] = 1;
    memo[1] = 1;
    for (int i = 1; i < n; i++) {
        ll sum = 0;
        for (int j = i; j > i - 6; j--) {
            sum += memo[mod(j, 6)];
            sum %= md;
        }
        memo[mod(i + 1, 6)] = sum;
    }
    return memo[mod(n, 6)];
}

int main()
{
    IOS;
    prepare(n);
    cout << solve(n);

    return 0;
}