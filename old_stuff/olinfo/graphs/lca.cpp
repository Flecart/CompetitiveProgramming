#include <cstdio>
#include <cassert>
#include <cstdlib>

static FILE *fr, *fw;

// Declaring variables
static int N;
static int Q;
static int T;
static int* A;
static int* B;
static int* C;
static int* U;
static int* V;
static long long int* res;

// Declaring functions
void inizia(int N, int T, int A[], int B[], int C[]);
long long int distanza1(int u, int v);
long long int distanza2(int u, int v);
long long int minimo(int u, int v);
long long int massimo(int u, int v);
void run(int Q, int T, int U[], int V[], long long int res[]);

// Functions ad-hoc for this grader
void run(int Q, int T, int U[], int V[], long long res[]) {
  for (int i = 0; i < Q; i++) {
    if (T == 0)
      res[i] = distanza1(U[i], V[i]);
    else if (T == 1)
      res[i] = distanza2(U[i], V[i]);
    else if (T == 2)
      res[i] = minimo(U[i], V[i]);
    else if (T == 3)
      res[i] = massimo(U[i], V[i]);
    else
      assert(!"Invalid value for T");
  }
}

int main() {
    fr = stdin;
    fw = stdout;

	// Reading input
	fscanf(fr, " %d %d %d", &N, &Q, &T);
	A = (int*)malloc((N-1) * sizeof(int));
	B = (int*)malloc((N-1) * sizeof(int));
	C = (int*)malloc((N-1) * sizeof(int));
	for (int i0 = 0; i0 < N-1; i0++) {
		fscanf(fr, " %d %d %d", &A[i0], &B[i0], &C[i0]);
	}
	U = (int*)malloc((Q) * sizeof(int));
	V = (int*)malloc((Q) * sizeof(int));
	for (int i0 = 0; i0 < Q; i0++) {
		fscanf(fr, " %d %d", &U[i0], &V[i0]);
	}

	// Calling functions
	inizia(N, T, A, B, C);
	res = (long long int*)malloc((Q) * sizeof(long long int));
	run(Q, T, U, V, res);

	// Writing output
	for (int i0 = 0; i0 < Q; i0++) {
		fprintf(fw, "%lld ", res[i0]);
	}
	fprintf(fw, "\n");

    fclose(fr);
    fclose(fw);
    return 0;
}

#include <bits/stdc++.h>
using namespace std; 
#define MAXN 100001
typedef long long ll; 

int timer;
int log_value = 17; 
int mode; 

struct info {
    ll all;
    ll prefix, suffix; 
    ll middle;
    info(int v): all(v), prefix(v), suffix(v), middle(v) {} 
    info(): info(0) {}

    // merges two info sections (in the right order)
    info operator+(const info &other) const {
        info new_info; 
        new_info.all = all + other.all; 
        new_info.prefix = max(prefix, max(all, all + other.prefix));
        new_info.suffix = max(other.suffix, max(other.all, other.all + suffix));
        new_info.middle = max(suffix + other.prefix, max(other.middle, middle));
        ll possibile_middle = max(new_info.all, max(suffix + other.all, all + other.prefix));
        new_info.middle = max(new_info.middle, possibile_middle); 
        return new_info;
    }

    void invert() {
        swap(prefix, suffix);
    }

    ostream &operator <<(ostream &out) const {
        out << all << " sol: " << middle << " p: " << prefix << " s: " << suffix  << endl; 
        return out;
    }
};
vector<vector<pair<int, int>>> adj(MAXN); 
vector<int> tin(MAXN), tout(MAXN);
vector<int> visited(MAXN);  
vector<vector<int>> lca_table(MAXN, vector<int>(log_value)); 
vector<vector<ll>> info_table; 
vector<vector<info>> info_table2;

function<ll(ll, ll)> lambda; 
// mode 1 and 2
auto get_sum = [](ll a, ll b) {
    return a + b;
};

// mode 3
auto get_min = [](ll a, ll b) {
    return min(a, b);
};



template<class T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    out << "[";
    for (T el : v) {
        out << el << ", ";
    }
    out << "]\n";
    return out;
}

// vertice, parent, cost from parent to vertice
void dfs(int v, int p, ll cost) {
    visited[v] = true; 
    tin[v] = timer++;
    // fill lca table: 
    lca_table[v][0] = p;

    // con migliore generalizzazione riesci a riscrivre sta parte senza if else.
    if (mode != 3) info_table[v][0] = cost; 
    else info_table2[v][0] = info(cost);
    for (int i = 1; i < log_value; i++) {
        lca_table[v][i] = lca_table[lca_table[v][i - 1]][i - 1];
        if (mode != 3) {
            ll last = info_table[v][i - 1];
            ll parent_last = info_table[lca_table[v][i - 1]][i - 1];
            info_table[v][i] = lambda(parent_last, last);
        } else {
            info_table2[v][i] = info_table2[v][i - 1] + info_table2[lca_table[v][i - 1]][i - 1];
        }
    }

    for (auto edge : adj[v]) {
        int to = edge.first;
        if (!visited[to]) {
            dfs(to, v, edge.second);
        }
    }
    tout[v] = timer++;
}

// check if v is ancestor of p
bool is_ancestor(int v, int p) {
    return (tin[v] <= tin[p]) and (tout[v] >= tout[p]);
}

int find_ancestor(int a, int b) {
    if (is_ancestor(a, b)) return a;
    else if (is_ancestor(b, a)) return b; 

    for (int i = log_value; i >= 0; --i) {
        if (!is_ancestor(lca_table[a][i], b)) a = lca_table[a][i];
    }
    // l'antenato è proprio il genitore del nodo così trovato
    // praticamente sto scomponendo l'intero della distanza fra 
    // il corrente e l'antenato!
    return lca_table[a][0]; 
}

ll get_info(int a, int b) {
    int ancestor = find_ancestor(a, b); 
    // risaliscono entrambi prendendo il valore che gli serve
    ll ans = mode == 2 ? LLONG_MAX : 0;

    for (int i = log_value; i >= 0; --i) {
        if (!is_ancestor(lca_table[a][i], ancestor)) {
            ans = lambda(ans, info_table[a][i]);
            a = lca_table[a][i]; 
        }
        if (!is_ancestor(lca_table[b][i], ancestor)) {
            ans = lambda(ans, info_table[b][i]); 
            b = lca_table[b][i];
        }
    }
    // ancora l'ultimo passo da contare
    if (a != ancestor) ans = lambda(ans, info_table[a][0]);
    if (b != ancestor) ans = lambda(ans, info_table[b][0]);
    return ans; 
}

ll get_info2(int a, int b) {
    int ancestor = find_ancestor(a, b); 
    info sinistra, destra;
    for (int i = log_value; i >= 0; --i) {
        if (!is_ancestor(lca_table[a][i], ancestor)) {
            sinistra = sinistra + info_table2[a][i];
            a = lca_table[a][i]; 
        }
        if (!is_ancestor(lca_table[b][i], ancestor)) {
            destra = destra + info_table2[b][i]; 
            b = lca_table[b][i];
        }
    }

    if (a != ancestor and b != ancestor) {
        sinistra = sinistra + info_table2[a][0]; // così c'è anche ancestor dentro
        destra = destra + info_table2[b][0];
        destra.invert();
    } else if (a == ancestor and b == ancestor) return 0; // input a = b
    else {
        // solo uno dei due è ancestor
        if (a == ancestor) {
            swap(a,b);
            swap(sinistra, destra); 
        }
        sinistra = sinistra + info_table2[a][0];
    }
    ll result = (sinistra + destra).middle;
    return max(0ll, result); // considera il cammino vuoto come sempre disponibile
}


void inizia(int N, int T, int A[], int B[], int C[]) {
    timer = 0;
    mode = T; 

    if (T == 3) {
        info_table2.assign(N + 1, vector<info>(log_value));
    } else {
        info_table.assign(N + 1, vector<ll>(log_value));
    }

    for (int i = 0; i < N - 1; i++) {
        if (T == 0) C[i] = 1;
        adj[A[i]].push_back({B[i], C[i]});
        adj[B[i]].push_back({A[i], C[i]});
    }
    lambda = get_sum; // standard
    if (mode == 2) lambda = get_min; 
    dfs(0, 0, 0);
	return ;
}

long long int distanza1(int u, int v) {
	return get_info(u, v);
}

long long int distanza2(int u, int v) {
	return get_info(u, v);
}

long long int minimo(int u, int v) {
	return get_info(u, v);
}

long long int massimo(int u, int v) {
	return get_info2(u, v);
}

