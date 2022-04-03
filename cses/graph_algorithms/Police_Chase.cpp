#include <bits/stdc++.h>

using namespace std;

// POLICE CHASE:
// This is an application of the min-cut max-flow theorem
// you can see the description and solution
// using edmond-karp algo here 
// https://cp-algorithms.com/graph/edmonds_karp.html#edmonds-karp-algorithm


// the main idea is to use edmonds-karp to get max-flow, which is equal to min-cut
// now we costruct a new graph of reachable vertices and see which vertice goes
// outside this new set.
typedef long long ll;

ll capacities[501][501];
vector<int> parents;
vector<set<int>> adj;
const ll kInf = LLONG_MAX;
const int source = 1;
int target;

ll bfs() {
    fill(parents.begin(), parents.end(), -1);
    parents[source] = -2;
    queue<pair<int, ll>> coda; // node, flow
    coda.push({source, kInf});

    while (!coda.empty()) {
        int curr = coda.front().first;
        ll flow = coda.front().second;
        coda.pop();

        for (int neigh : adj[curr]) {
            if (parents[neigh] == -1 and capacities[curr][neigh] > 0) {
                parents[neigh] = curr; 

                flow = min(flow, capacities[curr][neigh]);
                if (neigh == target) return flow;
                coda.push({neigh, flow});
            }
        }
    }

    return 0; // no augmenting path available
}

ll edmonds_karp() {
    ll max_flow = 0;
    ll flow;
    while ((flow = bfs())) {
        max_flow += flow;
        int curr = target; // ripercorri al contrario il tutto
        while (curr != source) {
            int parent = parents[curr];
            capacities[parent][curr] -= flow;
            capacities[curr][parent] += flow;
            curr = parent;
        } 
    }
    return max_flow;
}

void get_reach(int v, set<int> &reachable, vector<int> &visited) {
    reachable.insert(v);
    visited[v] = true;

    for (int to : adj[v]) {
        if (capacities[v][to] > 0 and !visited[to]) {
            get_reach(to, reachable, visited);
        }
    }
}

int main() {
    cin >> target;
    int m; cin >> m;
    adj.resize(target + 1);
    parents.resize(target + 1);
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;

        // gestisci caso in cui esista già il flow, e aggiorna la capacità
        capacities[from][to] = 1;
        capacities[to][from] = 1;
        adj[from].insert(to);
        adj[to].insert(from); 
    }

    cout << edmonds_karp() << endl;
    set<int> reachable;
    vector<int> visited(target + 1, false);
    // dfs on still reachable vertices
    get_reach(1, reachable, visited);

    // then loop through all vertices, looking for edges that are outside
    for (int i = 1; i <= target; ++i) {
        if (reachable.find(i) == reachable.end()) continue;

        for (int to : adj[i]) {
            if (reachable.find(to) != reachable.end() or capacities[i][to] != 0) continue;
            else cout << i << " " << to << endl;
        } 
    }
}
