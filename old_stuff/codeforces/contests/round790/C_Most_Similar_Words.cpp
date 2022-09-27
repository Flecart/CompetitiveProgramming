#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

int get_dist(string &s, string &p) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += abs(s[i] - p[i]);
    }
    return ans; 
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n); 
    int ans = (int) 1e9;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int value = get_dist(s[i], s[j]);
            if (value < ans) ans = value;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}