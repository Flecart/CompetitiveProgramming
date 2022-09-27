#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, l; 
vector<int> parents;
vector<set<int>> adj; 

// for the lca
int timer;
vector<int> tin, tout;
vector<vector<int>> up;

// ROUND TRIP
// in this problem, the main difficulty was to print the found cicle
// i managed to do this with the LCA binary lifting code i copied from 
// https://cp-algorithms.com/graph/lca_binary_lifting.html 
// that is: is_ancestor, lca, tin, tout,up, timer.

// I used the dfs to find the cicle, and if it wasnt a trivial cicle
// i found the ancestor and printed the path based on this
// after the ancestor was found, i just printed the paths.
// probably there is a easier solution for this problem.
// i solved this with O(V + E + O(LCA) + (path len))

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

int get_generations(int from, int ancestor) {
    int n = 0;
    while (from != ancestor) {
        from = parents[from];
        n++;
    }
    return n;
}

void print(int from, int ancestor, bool reverse) {
    if (!reverse) {
        while (from != ancestor) {
            cout << from + 1 << " ";
            from = parents[from];
        }
    } else {
        if (from == ancestor) return; 
        print(parents[from], ancestor, reverse);
        cout << from + 1 << " ";
    }
}

void print_solution(int to, int ance, int v) {
    int nodes = 2; //ancestor and repeated to node
    nodes += get_generations(to, ance);
    nodes += get_generations(v, ance);

    cout << nodes << endl;

    print(to, ance, false);
    cout << ance + 1 << " ";
    print(v, ance, true);
    cout << to + 1 << " ";
}

bool dfs(int v) {
    tin[v] = ++timer;
    up[v][0] = (parents[v] < 0) ? 0 : parents[v];
    for (int i = 1; i <= l; ++i) {
        up[v][i] = up[up[v][i-1]][i-1];
    }

    for (int to : adj[v]) {
        if (parents[to] == -1) {
            parents[to] = v;
            if (dfs(to)) return true; // if solved, just return!
        } else if (parents[v] != to) { // found a cicle (not trivial cicle), so print it
            int ancestor = lca(to, v);
            print_solution(to, ancestor, v);  
            return true;          
        }
    }

    tout[v] = ++timer;
    return false;
}

void solve() {
    for (int i = 0; i < n; ++i) {
        if (parents[i] == -1) {
            parents[i] = -2;
            if (dfs(i)) return; // if true, i have found a cicle and printed it!
        } 
    }

    // only called if the dfs cant find any solution
    cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    
    // weird stuff for the LCA
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));

    // for the dfs
    parents.assign(n, -1);
    adj.resize(n); 

    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    solve(); 
}