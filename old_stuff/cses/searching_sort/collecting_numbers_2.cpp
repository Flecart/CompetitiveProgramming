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
Collecting numbers 2: The main idea of this second parts, that builds upon the main idea of the first part
is that the number of rounds needed only depends on the position of the antecedent and posterior number.
eg. if 7 is in position x, the number of rounds needed to calculate the contribution of 7 to the answer only 
depends on the position of 6 and 8, no need to focus on other things.

so, if, lets say, i have to swap the numbers at position a and b, and lets say these values are x and y
i know that the numbers x and y have only a limited contribution to the answer (0 min, 4 max), i calculate
the contribution at the current position, i swap them and calculate the contribution this time.
I know that this is all they contribute too, no need to focus on other things, so i just calculate the offset
and sum this to the answer before the swap. Thats all
*/

int get_contribute(int ind[], int n, int id1, int id2) {
    // this relies on observation from collecting number 1 
    // the fact that if i have x, x + 1 should have an indices after this
    // or i cant get this
    int sum = 0;
    if (id1 < id2) swap(id1, id2);

    if (id1 - id2 == 1) {
        if (ind[id1] > ind[min(n, id1 + 1)]) sum++;
        if (ind[id1] < ind[id2]) sum++;
        if (ind[id2] < ind[max(0, id2 - 1)]) sum++;
    } else {
        if (ind[id1] < ind[max(0, id1 - 1)]) sum++;
        if (ind[id1] > ind[min(n, id1 + 1)]) sum++;
        if (ind[id2] < ind[max(0, id2 - 1)]) sum++;
        if (ind[id2] > ind[min(n, id2 + 1)]) sum++;
    }
    return sum;
}

int update_arrays(int values_at[], int ind[], int n) {
    // i just want to get the change of value 
    // compared to precedent contribute of the total sum!
    // should be constant in time this function
    prepare(a);a--;
    prepare(b);b--;

    int before_a = values_at[a] - 1;
    int before_b = values_at[b] - 1;
    int old_sum = get_contribute(ind, n, before_a, before_b);

    // actual swap of numbers here
    swap(values_at[a], values_at[b]);
    a = values_at[a] - 1;
    b = values_at[b] - 1;
    swap(ind[a], ind[b]);

    int curr_sum = get_contribute(ind, n, a, b);

    return curr_sum - old_sum;
}
 
int main()
{
    IOS;
    prepare(n);
    prepare(m);
    int arr[n];
    int ind[n];
    seea(arr, 0, n);
    rep(i, 0, n) {
        ind[arr[i] - 1] = i;
    }
    int sol = 1;
    rep(i, 1, n) {
        if (ind[i] < ind[i - 1]) sol++;
    }
    rep(j, 0, m) {
        int offset = update_arrays(arr, ind, n);
        sol += offset;
        cout << sol; nl;
    }
    
 
    return 0;
}