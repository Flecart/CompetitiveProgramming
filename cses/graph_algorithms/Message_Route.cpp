#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> parents;
vector<set<int>> adj;

const int start = 1;
int target;

// MESSAGE ROUTE:
// i just use a bfs to search for the shortest path possible
// i don't have weights, so the bfs is a good choice.

int search_bfs() {
    queue<pair<int, int>> q; // node, len of path
    q.push({start, 1}); 
    parents[start] = -1;

    while (!q.empty()) {
        int curr = q.front().first;
        int len = q.front().second;
        q.pop();
        for (int to : adj[curr]) {
            if (parents[to] == 0) {
                parents[to] = curr;
                if (to == target) {
                    return len + 1;
                }
                q.push({to, len + 1}); 
            }
        }
    }
   return 0;
}

void print_sol(int curr) {
    if (curr == start) {
        cout << start << " ";
        return;
    } else {
        print_sol(parents[curr]);
        cout << curr << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; 
    cin >> n >> m;
    target = n;
    adj.resize(n + 1);
    parents.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b; 
        adj[a].insert(b);
        adj[b].insert(a);
    } 

    int sol = search_bfs();
    if (sol > 0) {
        cout << sol << endl;
        print_sol(target);
        cout << endl;
    } else cout << "IMPOSSIBLE\n";
}