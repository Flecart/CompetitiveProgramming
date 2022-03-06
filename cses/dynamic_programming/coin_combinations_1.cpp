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

/* COIN COMBINATIONS 1:
I notice in this problem i don't need to calculate the number of combinations
with the mathematical formula. I just need to calculate it in terms of the 
possible coins i have and the total - curr_chosen_coin ways of doing it.
*/

ll memo[(int)10e6 + 1]{0}; 
int main()
{
    IOS;
    prepare(n);
    prepare(target);
    int arr[n];
    seea(arr, 0, n);
    for (int i = 0; i < n; i++) {
        memo[arr[i]] = 1;
    }

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i - arr[j] > 0) {
                memo[i] += memo[i - arr[j]];
                memo[i] %= md;
            }
        }
    }
    cout << memo[target];
    return 0;
}