#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX (2 * (int) 1e5 + 3)
vector<vector<int>> adj(MAX, vector<int>());
vector<int> heigh(MAX);

inline bool isLeaf(int node) {
    return adj[node].size() == 0;
}

int get_heigh(int node, int p) {
    int max_heigh = 0;
    for (int child : adj[node]) {
        if (child == p) continue; 
        max_heigh = max(max_heigh, get_heigh(child, node) + 1);
    }
    return heigh[node] = max_heigh;
}

int get_sol(int node, int parent) {
    // diametro in un sottoalbero oppure 
    // congiunzione con la radice attuale
    int max_value = 0;
    int maxh = 0, second_maxh = 0;
    for (int child : adj[node]) {
        if (child == parent) continue; 
        max_value = max(max_value, get_sol(child, node));

        if (heigh[child] > maxh) {
            second_maxh = maxh;
            maxh = heigh[child];
        } else if (heigh[child] > second_maxh) {
            second_maxh = heigh[child];
        }
     }

    int just_height; // max with height conjunction
    if (isLeaf(node)) {
        just_height = 0;
    } else if (adj[node].size() == 1) {
        just_height = heigh[node];
    } else {
       // due nuovi edge :D
        just_height = maxh + 2 + second_maxh;
    }

    return max(just_height, max_value);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int t; cin >> t;
        int tmp; cin >> tmp; 
        adj[t].push_back(tmp);
        adj[tmp].push_back(t);
    }

    get_heigh(1, 0);
    cout << get_sol(1, 0);   
}