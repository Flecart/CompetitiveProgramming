#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi; 
const int inf = 1e9;
vector<vi> adj; 
vi sol;
vi child_dir; 
vi toposort;
vector<bool> visited; 

// DP on toposorted stuff!

// fill sol values 
void get_values() {
    for (int i = 0; i < adj.size(); i++) {
        int node = toposort[i];
        for (auto n : adj[node]) {
            if (sol[node] < sol[n] + 1) {
                sol[node] = sol[n] + 1; 
                child_dir[node] = n;
            }
        }
    }
}

void tpsort(int v) {
    visited[v] = true; 
    for (auto n : adj[v]) {
        if (!visited[n]) tpsort(n);
    }
    toposort.push_back(v);
}

bool reachable(int v, int target) {
    visited[v] = true; 

    bool found = v == target ? true : false; 
    for (auto n : adj[v]) {
        if (!visited[n]) found |= reachable(n, target);
    }
    return found; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m; 
    adj.resize(n);
    visited.resize(n);
    sol.assign(n, -inf);
    sol[n - 1] = 1; // solo il nodo n - 1 è valido!
    child_dir.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;  a--; b--;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) tpsort(i);
        child_dir[i] = i; // punta a sé stesso, capisco che è la fine inq uesto modo;
    }
    visited.assign(n, false);
    if (!reachable(0, n - 1)) return cout << "IMPOSSIBLE\n", 0;

    get_values(); 
    int best_node = 0;
    int best_value = sol[0];
    cout << best_value << '\n';
    while (child_dir[best_node] != best_node) {
        cout << best_node + 1 << ' ';
        best_node = child_dir[best_node];
    }
    cout << best_node + 1;
}