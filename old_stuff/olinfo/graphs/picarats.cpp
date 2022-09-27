#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <climits>
#include <vector>
// constraints
#define MAXN 10000
#define MAXM 50000
#define MAXC 100
using namespace std; 
const int k_cant_reach = (int) 1e9 + 1;
struct edge {
    int node;
    int gain;
};
// input data
int N, M, C_0, a, b, c, i;
int P[MAXN];
vector<vector<edge>> adj(MAXN + 1); 

// vector(v, n): migliore modo per spendere n monete sulla path col nodo v
vector<vector<int>> memo(MAXN + 1, vector<int>(MAXC + 1, -1)); 

// ritorna il miglior modo di spendere le monete nel percorso con v come radice
int fill_memo(int v, int monete) {
    if (v == N - 1) return memo[v][monete] = (P[v] >> monete);
    if (memo[v][monete] != -1) return memo[v][monete];
    memo[v][monete] = k_cant_reach;
    int curr_best = k_cant_reach;
    for (int i = 0; i <= monete; ++i) {
        int node_value = (P[v] >> i);
        for (edge e : adj[v]) {
            int to_node = e.node; 
            int quantita_monete = e.gain + monete - i;
            if (memo[to_node][quantita_monete] != k_cant_reach) {
                int path_value = fill_memo(to_node, quantita_monete);
                curr_best = min(curr_best, max(node_value, path_value));
            }
        }
    }
    return memo[v][monete] = curr_best;
}

int get_ans() {
    int curr = INT_MAX; 
    for (int i = C_0; i >= 0; --i) {
        curr = min(curr, fill_memo(0, i));
    }
    return curr;
}

int main() {
  assert(3 == scanf("%d %d %d", &N, &M, &C_0));
  for (i = 0; i < N; i++) {
    assert(1 == scanf("%d", &P[i]));
  }
  for (i = 0; i < M; i++) {
    assert(3 == scanf("%d %d %d", &a, &b, &c));
    adj[a].push_back({b, c});
  }

  printf("%d\n", get_ans()); // print the result
  return 0;
}
