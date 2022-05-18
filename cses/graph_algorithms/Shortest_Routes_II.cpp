#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int kmax = 501;
const ll linf = 1e18;
unsigned long long graph[kmax][kmax];

void floyd_warshal(int n) {
    // this is a dp algorithm that finds all paths
    // for i = 1 to n, find the best path that can pass
    // though node 1..i. so at n, we will have all nodes
    // compexity is O(n3) 

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // see if i can get better cost if i pass though k 
                // instead of original path i - j
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < kmax; i++) {
        for (int j = 0; j < kmax; j++) {
            if (i != j) graph[i][j] = linf;
            // else use default global 0
        }
    }

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c; 
        graph[a][b] = graph[b][a] = min(graph[a][b], 1ull*c);
    }

    floyd_warshal(n);

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] != linf) cout << graph[a][b] << '\n';
        else cout << -1 << '\n';
    }
}