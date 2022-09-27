#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll x, y;
set<ll> sols;

bool good(ll n) {
    if (n > x or n > y) return false; 
    if (x % n == 1 and y % n == 1) return true; 
    if (x % n == 2 and y % n == 0) return true; 
    if (x % n == 0 and y % n == 2) return true; 
    return false; 
}

void solve() {
    sols.clear();
    cin >> x >> y;
    sols.insert(1);
    sols.insert(2);
    ll perimeter = x * 2 + y * 2 - 4;
    for (ll i = 3; i * i <= perimeter; i++) {
        if (perimeter % i == 0) {
            if (good(i)) sols.insert(i);
            if (good(perimeter / i)) sols.insert(perimeter / i);
        }
    }

    cout << sols.size() << ' ';
    for (auto s : sols) cout << s << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}