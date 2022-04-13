#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX (2 * (int) 1e5 + 3)
vector<vector<int>> adj(MAX, vector<int>());
vector<bool> matched(MAX);

inline bool isLeaf(int node) {
    return adj[node].size() == 0;
}

int get_sol(int node, int parent) {
    int ans = 0;
    for (int child : adj[node]) {
        if (child == parent) continue;
        if (isLeaf(child)) {
            // scelta credo greedy, di machare subito se foglia
            // bisognerebbe dimostrarlo
            if (!matched[node]) {
                matched[node] = true; // anche foglia = true, ma non necessario
                ans += 1;
            }
        } else {
            ans += get_sol(child, node); 
            if (!matched[node] and !matched[child]) {
                matched[node] = matched[child] = true;
                ans += 1;
            }
        }
    }
    return ans;
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
    cout << get_sol(1, 0);
}