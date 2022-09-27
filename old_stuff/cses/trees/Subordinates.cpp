#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX (2 * (int) 1e5 + 3)
vector<vector<int>> adj(MAX, vector<int>());
int memo[MAX];
// SUBORDINATES
// I don't think memo is needed. 
// but the idea is to use the recursive structure of the tree
// so i write the num of subordinates in function of the sub
// of the childs
int subordinates(int n) {
    if (memo[n] != -1) return memo[n];
    int ans = 0;
    for (int child : adj[n]) {
        ans += subordinates(child) + 1; // child + subordinati di child
    }
    return memo[n] = ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int tmp; cin >> tmp; 
        memo[i] = -1;
        adj[tmp].push_back(i);
    }
    memo[1] = -1;

    for (int i = 1; i <= n; i++) {
        cout << subordinates(i) << " ";
    }
}