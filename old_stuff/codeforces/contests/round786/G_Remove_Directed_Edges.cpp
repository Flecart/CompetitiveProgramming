#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;

vector<vi> adj; 
vector<int> tp; //toposort;
vector<int> dp; 
vector<bool> visited; 
vector<int> in_grade;
void toposort(int v) {
    visited[v] = 1; 
    for (auto i : adj[v]) if (!visited[i]) toposort(i);
    tp.push_back(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    dp.resize(n);
    visited.resize(n);
    in_grade.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        in_grade[b]++;
    }
    for (int i=  0; i < n; i++) {
        if (!visited[i]) toposort(i);

        if (in_grade[i] >= 2) dp[i] = 1; // end node
    }

    // toposort dp:
    for (int i = 0; i < n; i++) {
        // only on midde vertices
        if (adj[tp[i]].size() < 2 or in_grade[tp[i]] < 2) continue; // cant connect with those
        for (int j : adj[tp[i]]) {
            dp[tp[i]] = max(dp[tp[i]], dp[j] + 1);
        }
    }

    int mmax = 1;
    // count for start vertices
    for (int i = 0; i < n ; i++) {
        if (adj[i].size() >= 2) { // can be start
            for (auto j : adj[i]) mmax = max(mmax, dp[j] + 1);
        }
    }
    cout << mmax;
}