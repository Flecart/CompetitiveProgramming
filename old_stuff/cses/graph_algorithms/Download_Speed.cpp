#include <bits/stdc++.h>

using namespace std;

// DOWNLOAD SPEED:
// This is a classical flow problem.
// you can see the description and solution
// using edmond-karp algo here 
// https://cp-algorithms.com/graph/edmonds_karp.html#edmonds-karp-algorithm
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


int main() {
    cin >> target;
    int m; cin >> m;
    adj.resize(target + 1);
    parents.resize(target + 1);
    for (int i = 0; i < m; ++i) {
        int from, to;
        ll cost;
        cin >> from >> to >> cost;

        // gestisci caso in cui esista già il flow, e aggiorna la capacità
        if (adj[from].find(to) == adj[from].end()) {
            capacities[from][to] = cost;
            capacities[to][from] = 0;
            adj[from].insert(to);
            adj[to].insert(from); 
        } else {
            capacities[from][to] += cost;
        }
    }

    cout << edmonds_karp() << endl;
}
