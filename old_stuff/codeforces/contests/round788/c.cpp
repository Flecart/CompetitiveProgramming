#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
struct dsu {
    vector<int> vv;
    dsu(int n) {
        vv.assign(n, -1);
    }

    void join(int a, int b) {
        int ha = head(a);
        int hb = head(b);
        if (ha == hb) return; // same set
        if (vv[ha] < vv[hb]) {
            vv[ha] += vv[hb]; // the head contains the rank of the set
            vv[hb] = ha;
        } else {
            vv[hb] += vv[ha];
            vv[ha] = hb;
        }
    }

    int head(int a) {
        if (vv[a] < 0) return a; // if negative, its a head
        return vv[a] = head(vv[a]); // path compress
    }

    int size(int a) {
        return -vv[head(a)];
    }
};

ll fast_pow(ll base, ll exp) {
    ll ans = 1; 
    while (exp) {
        if (exp & 1) ans = (ans * base) % mod; 
        base = (base * base) % mod; 
        exp >>= 1;
    }
    return ans; 
}

void solve() {
    int n; 
    cin >> n;
    dsu d(n);
    vector<int> a(n), b(n), c(n);
    vector<bool> chosen(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    
    for (int i = 0; i < n; i++) {
        cin >> b[i]; b[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i]; c[i]--;
    }

    for (int i = 0; i < n; i++) {
        d.join(a[i], b[i]);
    }

    for (int i = 0; i < n; i++) {
        if (c[i] >= 0) {
            chosen[d.head(c[i])] = true;
        }
    }

    int valid_sets = 0;

    for (int i = 0; i < n; i++) {
        if (d.vv[i] >= 0) continue;
        if (chosen[i]) continue; 
        if (d.size(i) == 1) continue;
        valid_sets++;
    }

    cout << fast_pow(2, valid_sets) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}