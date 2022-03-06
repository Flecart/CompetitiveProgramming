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
const ll mod = 1000000007;

char paths[1000][1000];
ll cost[1000][1000];

/*
GRID PAHTS:
the main idea is to compute the number of ways to get to tile i,j
with the sum of the ways from tile i-1,j and i,j-1 as we only have
these two ways of moving
*/

int main()
{
    IOS;
    prepare(n);
    for (int i = 0; i < n; i++) {
        cin >> paths[i];
    }
    cost[0][0] = paths[0][0] == '*' ? 0 : 1;

    for (int i = 1; i < n; i++) {
        if (paths[0][i] == '*') cost[0][i] = 0;
        else cost[0][i] = cost[0][i - 1];

        if (paths[i][0] == '*') cost[i][0] = 0;
        else cost[i][0] = cost[i - 1][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (paths[i][j] == '*') cost[i][j] = 0;
            else {
                ll left = cost[i][j - 1];
                ll upper = cost[i - 1][j];
                cost[i][j] = (left + upper) % mod;
            }
        }
    }
    cout << cost[n - 1][n - 1];
    return 0;
}