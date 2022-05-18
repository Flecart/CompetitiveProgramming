#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int kmax = 2501;
const ll linf = 1e18;
ll dist[kmax];

// 1 -> raggiungibile da 1
// 2 -> può raggiungere n
int states[kmax]; // se raggiungibile da 1 e n ed è in in ciclo, ecco qui il checker!

// Bellman ford algo
struct edge {
    int from; 
    int to; //
    int w; // weight
};
vector<edge> edges; 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // startnode is 1, so default dist[1] = 0 with global
    for (int i = 2; i < kmax; i++) dist[i] = linf;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int from, to ,w; 
        cin >> from >> to >> w; 
        // negative to obtain the maximum!
        edges.push_back({from, to, -w});
    }
    states[1] = 1;
    states[n] = 2;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            auto [from, to, w] = edges[j];
            if (dist[from] + w < dist[to]) {
                dist[to] = dist[from] + w;
            }

            if (states[from] & 1) states[to] |= 1;
            if (states[to] & 2) states[from] |= 2;
        }
    }

    // perform another relaxation cycle for detecting cycles
    for (int j = 0; j < m; j++) {
        auto [from, to, w] = edges[j];
        if (dist[from] + w < dist[to] and states[from] == 3 and states[to] == 3) {
            cout << -1; // negative cycles to n!
            return 0;
        }
    }

    cout << -dist[n]; 
}