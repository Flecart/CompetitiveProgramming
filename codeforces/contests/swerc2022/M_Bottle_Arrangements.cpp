#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int wmax, rmax;

void solve() {
    wmax = rmax = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2; 
        if (tmp1 > rmax) rmax = tmp1;
        if (tmp2 > wmax) wmax = tmp2; 
    } 
    if (rmax + wmax > n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < rmax; i++) cout << "R";
    for (int i = 0; i < n - rmax; i++) cout << "W";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}