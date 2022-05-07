#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
vector<vector<int>> adj;
vi parent;
vi size_of_comp;
vb visited;

const int mod = (int) 1e9 + 7;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void find(int v, int par) {
    parent[v] = par;
    size_of_comp[par]++;
    visited[v] = true; 
    for (auto i : adj[v]) {
        if (!visited[i]) find(i, par);
    }
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    parent.assign(n, -1);
    visited.assign(n, 0);
    size_of_comp.assign(n, 0);
    adj.assign(n, vi());
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    for (auto &i : b) {
        cin >> i;
        i--;
    }
    for (auto &i : c) {
        cin >> i; i--;
    }

    for (int i = 0; i < n; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    int comps = 0;
    for (int i = 0; i < n; i++) {
        // ogni dfs è una connected comp
        if (!visited[i]) {
            find(i, i);
            comps++;
        }
    }

    visited.assign(n, false); // using for marks
    for (int i = 0; i < n; i++) {
        if (c[i] != -1 and !visited[parent[c[i]]]) {
            visited[parent[c[i]]] = true; 
            comps--;
        } else if (!visited[parent[i]] and size_of_comp[parent[i]] == 1) {
            comps--;
            visited[parent[i]] = true;
        }
    }
    // cerr << comps << endl;

    cout << binpow(2, comps) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}