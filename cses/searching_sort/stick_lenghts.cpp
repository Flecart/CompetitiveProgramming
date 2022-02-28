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
#define seea(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define seev(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define sees(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}
#define prepare(x) int x; cin >>x;
//----------CONSTANTS----------
const int inf = INT_MAX;
const ll linf = LLONG_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

ld mean(int arr[], int len) {
    ll sum = 0;
    rep(i, 0, len) {
        sum += arr[i];
    }
    return sum / (ld) len;
}

int main()
{
    IOS;
    int n; cin >> n;
    int arr[n];
    seea(arr, 0, n);
    sort(arr, arr +n );
    int median = arr[n / 2];

    ll solution = 0;
    rep(i, 0, n) {
        solution += abs(arr[i] - median);
    }

    cout << solution;
    nl;
    return 0;
}