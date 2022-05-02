#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int a, b; 
    cin >> a >> b; 
    if (b % a != 0) cout << 0 << ' ' << 0 << '\n';
    else cout << 1 << ' ' <<  b / a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}