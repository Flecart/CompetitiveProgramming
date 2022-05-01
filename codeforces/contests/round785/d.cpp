#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
ll b, q, y, c, r, z; 
ll last_el_sec; 
ll last_el_fir; 
vector<ll> factors;
bool possible() {

    // check if actually can be done
    if (r % q != 0) return false; // check divs
    if (abs(c - b) % q != 0) return false;  // check start point

    last_el_sec = c + r * (z - 1); 
    last_el_fir = b + q * (y - 1); 
    // last element is in the subsequence
    if (last_el_sec > last_el_fir) return false;
    // same check for first
    if (c < b) return false;
    return true; 
}

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b); 
    if (a == 0) return b; 
    return gcd(b % a, a);
}



void trial_division() {
    ll n = r; 
    ll other = q; 
    for (long long d = 1; d * d <= n; d++) {
        if (n % d == 0) {
            if (other * d / gcd(other, d) == n) factors.push_back(d);
            if (d * d == n) continue;
            if (other * (n / d) / gcd(other, n/d) == n) factors.push_back(n / d);
        }
    }
}

void solve() {
    factors.clear();
    cin >> b >> q >> y >> c >>r >> z; 
    if (!possible()) {
        cout << 0 <<  '\n';
        return;
    }

    if (c - r < b or last_el_sec + r > last_el_fir) {
        cout << -1 << '\n'; return;
    }

    trial_division();
    ll sol = 0;
    for (auto div : factors) {
        ll els = r / div; // number of elements i can fit both sides;
        sol = (sol + els * els) % mod; 
    }
    cout << sol << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}