#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s, t; 
    cin >> s >> t; 
    if (t == "a") return cout << 1 << '\n' ,void(); 

    bool has_a = false; 
    for (auto ch : t) {
        if (ch == 'a') {
            has_a = true; 
            break; 
        }
    } 
    // ha una a ed è diverso da  "a" , può crescere all'infinito
    if (has_a) return cout << -1 << '\n', void(); 

    ll ans = pow(2, s.size()); 
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}