#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
// https://codeforces.com/contest/1670/problem/D
// magic formula for the number of triangles after 3n steps
constexpr ll f(ll n) {
    return 3 * n * n;
}

int bin_search(int target) {
    int l = 0, h = (int) 1e5; 
    while (l < h - 1) {
        int mid = (l + h) / 2;
        if (f(mid) < target) l = mid;
        else h = mid;
    }
    return l;
}

void solve() {
    int n; cin >> n; 
    n = (n + 1) / 2;
    int lowindex = bin_search(n);
    int curr_offset = max(0, lowindex * 2); 
    int ans;
    if (f(lowindex) + curr_offset >= n) ans = 3 * lowindex + 1;
    else if (f(lowindex) + 2 * curr_offset + 1 >= n) ans = 3 * lowindex + 2;
    else ans = 3 * lowindex + 3;
    // cerr << lowindex << endl;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}