#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

long long profitto_massimo(int, int[], int[], int[]);

int main(){
    int n;
    FILE *in = stdin, *out = stdout;
    assert(fscanf(in, "%d", &n) == 1);

    int *u = (int*)calloc(n-1, sizeof(int));
    int *v = (int*)calloc(n-1, sizeof(int));
    int *w = (int*)calloc(n-1, sizeof(int));

    for(int i=0; i<n-1; i++)
      assert(fscanf(in, "%d%d%d", u + i, v + i, w + i) == 3);

    long long answ = profitto_massimo(n, u, v, w);
    fprintf(out, "%lld\n", answ);

    free(u);
    free(v);
    free(w);

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}
#include <bits/stdc++.h>
#define MAX (int) 1e6 + 3
using namespace std; 
typedef long long ll;

vector<vector<pair<int, int>>> adj(MAX); // (to, cost)

vector<ll> dp(MAX, -1); 
vector<ll> dp2(MAX, -1); 

ostream &operator<<(ostream &out, pair<int, int> p) {
    out << p.first << " " << p.second;
    return out;
}

inline bool is_leaf(int v) {
    return adj[v].size() == 1;
}

ll get_max(int v, int p, bool prendo) {
    if (dp[v] != -1) return prendo ? dp[v] : dp2[v];
    if (p != 0 and is_leaf(v)) {
        dp[v] = 0;
        dp2[v] = 0;
        return 0ll;
    }

    // nodi del massimo e del secondo max
    // f sta per first, s sta per second
    int fmax = -1, smax = -1;
    ll fcost = 0, scost = 0;
    ll sum = 0;
    for (auto e : adj[v]) {
        if (e.first == p) continue; 
        ll lasciato = get_max(e.first, v, false); 
        sum += lasciato;

        ll preso = get_max(e.first, v, true) + e.second;
        ll result = preso - lasciato;  
        if (result > scost) {
            scost = result;
            smax = e.first; 
            if (scost > fcost) {
                swap(scost, fcost);
                swap(fmax, smax); 
            }
        }
    }
    
    dp[v] = sum + fcost; 
    dp2[v] = dp[v] + scost; 

    if (prendo) return dp[v];
    else return dp2[v];
}


long long profitto_massimo(int N, int U[], int V[], int W[]){
    for (int i = 0; i < N - 1; i++) {
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }
    // get_max(3, 0, false);
    // for (int i = 1; i <= N; i++) {
        // cerr << i << " " << dp[i] << " " << dp2[i] << endl;
    // }
    return max(get_max(3, 0, false), get_max(3, 0, true));
}
