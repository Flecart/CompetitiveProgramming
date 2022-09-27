#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

vi b(4001);
vi w(4001);
vb visited(4001);
vector<vi> adj;
string s;

int fill_colours(int v, int p) {
    visited[v] = 1;

    int ans = 0;
    for (auto n : adj[v]) {
        if (!visited[n]) {
            ans += fill_colours(n, v);
        }
    }

    for (auto n : adj[v]) {
        if (n == p) continue;
        b[v] += b[n];
        w[v] += w[n];
    }
    if (s[v - 1] == 'W') w[v]++;
    else b[v]++;

    if (b[v] == w[v]) return ans + 1;
    else return ans; 
}
void solve() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        int tmp; 
        cin >> tmp;
        adj[i].push_back(tmp);
        adj[tmp].push_back(i);
    }
    cin >> s;

    cout << fill_colours(1, -1) << '\n';
    fill(b.begin(), b.end(), 0);
    fill(w.begin(), w.end(), 0);
    fill(visited.begin(), visited.end(), 0);
    adj.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}