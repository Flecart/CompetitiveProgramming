#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int kmax = 1e5 + 2;
const int mod = 1e9 + 7;
int n, m; 
ll dp[kmax];
vector<int> tp; // toposort; 
vector<bool> visited(kmax); 
vector<vector<int>> adj(kmax);

void toposort(int v) {
    visited[v] = true; 
    for (auto n : adj[v]) {
        if (!visited[n]) toposort(n);
    }
    tp.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, c; 
        cin >> a >> c; a--; c--;
        adj[a].push_back(c);
    }
    dp[n - 1] = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) toposort(i);
    }
    for (int i = 0; i < n; i++) {
        for (auto j : adj[tp[i]]) { 
            dp[tp[i]] = (dp[tp[i]] + dp[j]) % mod;
        }
    }
    cout << dp[0]; 
}