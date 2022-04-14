#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<pair<ll, int>>> adj; // cost, node
vector<ll> costs;
void dijkstra() {
    costs[1] = 0;

    set<pair<ll, int>> queue; // (costo, nodo)
    queue.insert({0, 1});
    while (queue.size() > 0) {
        auto [p_cost, node] = *(queue.begin());
        queue.erase(queue.begin());
        for (auto child : adj[node]) {
            auto [c_cost, to] = child;
            ll t_cost = p_cost + c_cost; 
            if (t_cost < costs[to]) {
                queue.erase({costs[to], to});
                queue.insert({t_cost, to});
                costs[to] = t_cost;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    adj.resize(n + 1);
    costs.assign(n + 1, LLONG_MAX);
    for (int i = 0; i < k; i++) {
        int from, to, cost;
        cin >> from >> to >> cost; 

        adj[from].push_back({cost, to});
    }

    dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << costs[i] << " ";
    }
}