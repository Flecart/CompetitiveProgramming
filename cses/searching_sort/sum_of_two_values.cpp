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
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int main()
{
    int n, x;
    cin >> n >> x;

    pii arr[n];
    rep(i, 0, n) {
        int x; cin >> x;
        arr[i] = {x, i + 1};
    }; 
    sort(arr, arr + n);

    int l = 0, h = n - 1;
    while (l < h) {
        int sum = arr[l].F + arr[h].F;
        if (sum < x) l++;
        else if (sum > x) h--;
        else {
            cout << arr[l].S << " " << arr[h].S;
            nl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}