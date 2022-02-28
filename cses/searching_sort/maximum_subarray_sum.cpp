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

ll median(ll arr[], int low_limit, int mid, int high_limit) {
    ll left_sum = -inf;
    ll sum = 0;
    rev(i, mid, low_limit - 1) {
        sum += arr[i];
        if (sum > left_sum) left_sum = sum;
    }

    ll right_sum = -inf;
    sum = 0;
    rep(i, mid + 1, high_limit + 1) {
        sum += arr[i];
        if (sum > right_sum) right_sum = sum;
    }
    return left_sum + right_sum;
}

ll solve(ll arr[], int l, int h) {
    if (l == h) return arr[l];
    if (l > h) return -inf;
    int mid = (l + h) / 2;
    ll left = solve(arr, l, mid);
    ll right = solve(arr, mid + 1, h);
    ll mezzo = median(arr, l, mid, h);
    return max(left, max(right, mezzo));
}

int main()
{
    int n; cin >> n;
    ll arr[n];
    seea(arr,0, n);
    cout << solve(arr, 0, n - 1);
    nl;
    
    return 0;
}