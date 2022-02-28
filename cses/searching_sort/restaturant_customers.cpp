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
//----------CONSTANTS----------
const ll inf = INT_MAX;
const ld ep = 0.0000001;
const ld pi = acos(-1.0);
const ll md = 1000000007;

int main()
{
    int n;
    cin >> n;
    pii store[n];

    rep(i,0,n) {
        int a, b;
        cin >> a >> b;
        store[i] = {a,b};
    }
    sort(store, store + n);
    priority_queue<int, vector<int>, greater<int>> queue;

    int sum = 0;
    int max = 0;
    rep(i,0,n) {
        // delete people that are exiting from the restaurant
        while (!queue.empty() && queue.top() <= store[i].F) {
            queue.pop();
            sum -= 1;
        }
        sum += 1;
        queue.push(store[i].S);
        if (max < sum) max = sum;
    }

    cout << max;
    nl;
}