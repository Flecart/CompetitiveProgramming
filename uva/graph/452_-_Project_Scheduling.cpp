#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<set<int>> adj; 
vector<int> values; 
vector<int> memo; 

int get_ans(int v) {
    if (memo[v] != 0) return memo[v]; 
    int curr_node = values[v]; 
    int child_max = 0; 
    for (int i : adj[v]) {
        int curr = get_ans(i);
        if (child_max < curr) {
            child_max = curr; 
        }
    }
    return memo[v] = child_max + curr_node; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; 
    cin.ignore(); 
    cin.ignore(); 
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << endl; // PE error if
        adj.assign(26, set<int>()); 
        memo.assign(26, 0); 
        values.clear(); 

        string line;
        char task;
        string dependencies;
        int n_letters = 0;
        while (getline(cin, line) && line != "") {
            n_letters += 1;
            int curr;
            stringstream ss(line);
            ss >> task >> curr;
            int pos = task - 'A'; 
            values.push_back(curr); 
            if (ss >> dependencies) {
                for (int i = 0; i < dependencies.size(); ++i) {
                    int ch = dependencies[i] - 'A';
                    adj[ch].insert(pos); 
                }
            }
        }

        int ans = 0; 
        for (int i = 0; i < n_letters; ++i) {
            ans = max(ans, get_ans(i));
        }
        cout << ans << endl; 
    }
}