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
#define cspace << " " << 
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
Collecting numbers 1:
Observation 1:
in one round, if i take x (lets say its at pos I0), i have to take x + 1, x + 2 and so on.
This is only possible if x + 1, x + 2 is in a position after I0, if i take x + 1 at position I1
i can take x + 2 iff I2 is after  I2, else i have to add a round in order to take it in this way.

So i can order the input array, and begin to take 1, 2 ... , n in order, counting if i can take with positions.
*/

int main()
{
    IOS;
    prepare(n);
    pii arr[n];
    rep(i, 0, n) {
        prepare(x);
        arr[i] = {x, i};
    }
    sort(arr, arr + n);
    int ans = 1;
    int index = arr[0].S;
    rep(i, 1, n) {
        if (arr[i].S < index) {
            ans += 1;
        }
        index = arr[i].S;

    }

    cout << ans; nl;

    return 0;
}