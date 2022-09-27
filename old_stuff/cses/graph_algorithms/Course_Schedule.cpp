#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> adj; 
vector<int> cicledet;
vector<bool> visited;
vector<int> solution;

bool visit(int v) {
    visited[v] = true; 
    cicledet[v] = 1; 
    for (auto neigh : adj[v]) {
        if (cicledet[neigh] == 1) {
            return true; // ha cicli
        }
        if (visited[neigh]) continue; 
        if (visit(neigh)) return true;
    }
    cicledet[v] = 2;
    solution.push_back(v);
    return false; 
}

bool has_cicle() {
    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            if (visit(i)) return true; // se trova ciclo
        }
    }
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b;
    cin >> n >> m; 
    adj.resize(n);
    cicledet.resize(n);
    visited.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        adj[a].push_back(b); 
    }

    if (has_cicle()) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(solution.begin(), solution.end());
    for (auto i : solution) cout << i + 1 << ' ';
}