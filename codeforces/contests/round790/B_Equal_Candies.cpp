#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

void solve() {
    int n; cin >> n;
    vi arr(n);
    int mmin = (int)1e9;
    for (auto &i : arr) {
        cin >> i;
        if (i < mmin) mmin = i;
    }
    ll ans = 0;
    for (auto i : arr) {
        ans += (i - mmin);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}