#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int table[10];

void solve() {
    memset(table, 0, sizeof(table));
    int n; cin >> n;
    int beauty, diff;
    for (int i = 0; i < n; i++) {
        cin >> beauty >> diff;
        diff--;
        if (table[diff] < beauty) table[diff] = beauty;
    }

    int sol = 0;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 0) {
            cout << "MOREPROBLEMS\n";
            return;
        }
        sol += table[i];
    }
    cout << sol << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}