#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

void solve() {
    int n, q; 
    cin >> n >> q; 
    vi arr(n);
    vi sums(n);
    for (auto &i : arr) cin >> i;

    sort(arr.rbegin(), arr.rend());    
    sums[0] = arr[0];
    for (int i = 1; i < n; i++) {
        sums[i] = arr[i] + sums[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int query;
        cin >> query; 
        auto ans_idx = lower_bound(sums.begin(), sums.end(), query);
        if (ans_idx == sums.end()) {
            cout << -1 << '\n';
        } else {
            cout << (ans_idx - sums.begin() + 1) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}