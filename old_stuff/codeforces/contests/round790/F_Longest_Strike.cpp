#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
const int kmax = 2 * 1e5 + 2;
map<int, int> table;
void solve() {
    int n, k; 
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp; 
        table[tmp]++;
    }
    int ans = -1; 
    int curr = -1;
    pair<int, int> ans_p; 
    int last_value;
    int last_idx; // inizio della seq
    bool found = false; 
    for (auto p : table) {
        if (!found and p.second < k) continue; 
        else if (!found and p.second >= k) {
            // initialize values;
            last_value = p.first; 
            last_idx = p.first;
            curr = 1; 
            found = true; 

            if (curr > ans) {
                ans = curr; 
                ans_p = {p.first, p.first};
            }
            continue; 
        }

        if (p.first == last_value + 1 and p.second >= k) {
            curr++;
        } else {
            if (curr > ans) {
                ans = curr; 
                ans_p = {last_idx, last_value};
            }
            if (p.second < k) found = false; 
            else {
                last_idx = p.first; 
                curr = 1;
            }
        }
        last_value = p.first; 
    }

    if (curr != -1 and curr > ans) {
        ans = curr; 
        ans_p = {last_idx, last_value};
    }

    if (ans != -1) {
        cout << ans_p.first << ' ' << ans_p.second << '\n';
    } else {
        cout << -1 << '\n';
    }
    table.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}