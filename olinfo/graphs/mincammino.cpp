#include <vector>
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

// Declaring functions
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D);

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    vector<int> X(M), Y(M), P(M), D(N);
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i] >> P[i];
    }

    // Calling functions
    mincammino(N, M, move(X), move(Y), move(P), D);

    // Writing output
    for(int d : D) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}

vector<set<pair<int, int>>> adj; // peso, arrivo
vector<bool> visited; 
void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<int> &D) {
    adj.resize(N);
    visited.assign(N, false);
    for (int i = 0; i < M; i++) {
        adj[X[i]].insert({P[i], Y[i]});
    } 
    for (int i = 0; i < N; i++) {
        D[i] = INT_MAX;
    }

    // dijkstra 
    set<pair<int,int>> coda; // distanza, nodo (distanza mantenuta solo per l'ordine) 
    coda.insert({0,0});
    D[0] = 0;
    while (coda.size() > 0) {
        pair<int,int> tmp = *coda.begin();
        int curr_node = tmp.second; 
        visited[curr_node] = true; 
        coda.erase(coda.begin()); 

        for (auto e : adj[curr_node]) {
            int peso = e.first;
            int to = e.second; 

            if (D[to] > D[curr_node] + peso) D[to] = D[curr_node] + peso; 
            if (!visited[to]) {
                coda.insert({D[to], to}); 
            }
        }
    }

    /* BUGGED (NON ME LO RICORDAVO BENE)  DIJKSTRA 
    set<pair<int, pair<int, int>>> coda; // peso, partenza, arrivo
    D[0] = 0;
    visited[0] = true; 
    for (auto edge : adj[0]) {
        coda.insert({edge.first, {0, edge.second}}); 
    }

    while (coda.size() > 0) {
        pair<int, pair<int, int>> edge = *coda.begin(); 
        coda.erase(coda.begin());
        int peso = edge.first; 
        int from = edge.second.first; 
        int to = edge.second.second;
        // explora questo nodo e aggiorna la sua distanza 
        if (D[to] > D[from] + peso) D[to] = D[from] + peso; 

        if (!visited[to]) {
            for (auto edge : adj[to]) {
                coda.insert({edge.first, {to, edge.second}}); 
            }
        }
        visited[to] = true; 
    }
    */

    for (int i = 0; i < N; i++) {
        if (D[i] == INT_MAX) D[i] = -1; 
    }
}
