#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<int>> adj;
vector<int> states;

// BUILDING TEAMS
// This was a coloured dfs, i just searched the whole graph with a 
// colour (represented by the boolean) if i liked the node's colour
// it was ok, else i returned false and reported the error (for
// example this case could happen if i have a triangle in the graph)

// is_first -> 1
// !is_first -> 2
bool dfs(int v, bool is_first) {
    if (states[v] != 0) return false; 
    if (is_first) states[v] = 1;
    else states[v] = 2;

    for (int to : adj[v]) {
        if (states[to] == 1 and is_first) return false;
        else if (states[to] == 2 and !is_first) return false; 
        else if (states[to] == 0) {
            if (!dfs(to, !is_first)) return false;
        }
    }
    return true; // se tutto apposto
}

bool can_bipart(int n) {
    for (int i = 1; i <= n; i++) {
        // visita se non è visitato.
        // se è impossibile colorare, ritorna falso.
        if (states[i] == 0 and !dfs(i, true)) return false;
    }
    return true; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    states.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[a].insert(b);
        adj[b].insert(a);
    }

    if (can_bipart(n)) {
        for (auto sol : states) {
            if (sol == 0) continue; // causa 0 indexing, just ignore
            cout << sol << " ";
        }
        cout << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
}