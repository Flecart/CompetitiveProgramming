#include <bits/stdc++.h>

using namespace std;

// SCHOOL DANCE:
// utilizzo di una modellizzazione di un edmond karp
// al massimo utilizzo 1 quindi la parte difficile è mettere bene i pesi


vector<set<int>> adj;
vector<int> parents;
long long capacities[1200][1200];
const int kInf = INT_MAX;
const long long start = 0;
long long finish;
int boys, girls, m;

long long bfs() {
    fill(parents.begin(), parents.end(), -1);
    parents[start] = -2;
    queue<pair<int, long long>> q; // node, flow 
    q.push({start, kInf});

    while (!q.empty()) {
        int node = q.front().first;
        long long flow = q.front().second;
        q.pop();
        for (int neigh : adj[node]) {
            if (parents[neigh] == -1 and capacities[node][neigh] > 0) {
                parents[neigh] = node;
                flow = min(flow, capacities[node][neigh]);
                if (neigh == finish) return flow;
                q.push({neigh, flow});
            }
        }
    }
    // if cant find, just return a false value;
    return 0;
}

long long edmonds_karp() {
    long long max_flow = 0;
    long long flow;
    while ((flow = bfs())) {
        max_flow += flow;
        int curr = finish;
        while (curr != start) {
            int parent = parents[curr];
            capacities[parent][curr] -= 1;
            capacities[curr][parent] += 1;
            // cerr << "(" << curr << ", " << parent << ")\n";
            curr = parent;
        }
    }
    return max_flow;
}

int main() {
    cin >> boys >> girls >> m;
    // 0 source , 1-boys, boys + 1 - boys + girls, the last one
    int max_n = boys + girls + 2;
    finish = max_n - 1;
    adj.resize(max_n);
    parents.resize(max_n);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        b = boys + b; 

        // source collegato direttamente con le girls
        adj[0].insert(a);
        capacities[0][a] = 1;
        capacities[a][0] = 0;

        // collegamenti boys-girls, però non li conto nel max-flow
        adj[a].insert(b);
        adj[b].insert(a);
        capacities[a][b] = 1;
        capacities[b][a] = 0;

        adj[b].insert(finish);
        capacities[b][finish] = 1;
        capacities[finish][b] = 0;
    }

    cout << edmonds_karp() << endl;
    

    for (int i = 1; i <= boys; i++) {
        for (int girl : adj[i]) {
            if (capacities[i][girl] == 0) {
                cout << i << " " << girl - boys<< endl;
            }
        }
    }
}