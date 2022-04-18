#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 2 * (int) 1e5 + 2
pair<int, int> tasks[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first;
        cin >> tasks[i].second;
    }
    sort(tasks, tasks + n);
    ll start = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        start += tasks[i].first;
        ans += tasks[i].second - start; 
    }

    cout << ans; 
}