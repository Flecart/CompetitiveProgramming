#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> table;
int n, m;

ll get_values(int x, int y) {
    ll ans = table[x][y];
    int i = x - 1, j = y - 1;
    while (i >= 0 and j >= 0) {
        ans += table[i][j];
        i--;
        j--;
    }
    i = x + 1;
    j = y + 1;
    while (i < n and j < m) {
        ans += table[i][j];
        i++;
        j++;
    }
    i = x + 1;
    j = y - 1;
    while (i < n and j >= 0) {
        ans += table[i][j];
        i++;
        j--;
    }

    i = x - 1;
    j = y + 1;
    while (i >= 0 and j < m) {
        ans += table[i][j];
        i--;
        j++;
    }
    return ans; 
}

void solve() {
    cin >> n >> m;
    table.assign(n, vi(m));
    for (auto &i : table) {
        for (auto &j : i) cin >> j;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, get_values(i, j));
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