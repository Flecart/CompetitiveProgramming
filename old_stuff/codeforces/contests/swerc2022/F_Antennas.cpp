#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 200010
const int inf = 1e9; 

int p[MAX], dis[MAX], a[MAX];
struct segtree {
    pair<int, int> val[800010];
    void build(int x, int l, int r, int *a) {
        if (l == r) val[x] = {a[l], l};
        else {
            int mid = l + r >> 1;
            build(x << 1, l, mid, a);
            build(x << 1 | 1, mid + 1, r, a);
            val[x] = max(val[x << 1], val[x << 1 | 1]);
        }
    }

    pair<int, int> query(int x, int l, int r, int L, int R) {
        if (l > R or L > r) return {-inf, -1};
        if (L <= l and r <= R) return val[x]; 
        int mid = l + r >> 1; 
        return max(query(x << 1, l, mid, L, R), query(x << 1 | 1, mid + 1, r, L, R));
    }

    void rmv(int x, int l, int r, int k) {
        if (l == r) {
            val[x] = {-inf, -1};
            return; 
        }

        int mid = l + r >> 1;
        if (k <= mid) rmv(x << 1, l , mid, k);
        else rmv(x << 1 | 1, mid + 1, r, k); 
        val[x] = max(val[x << 1], val[x << 1 | 1]);
    }
} t1, t2;

void solve() {
    int n, j, k; 
    cin >> n >> j >> k; 
    for (int i = 1; i <= n; i++) cin >> dis[i];
    for (int i = 1; i <= n; i++) a[i] = i + dis[i];
    t1.build(1, 1, n, a); 
    for (int i = 1; i <= n; i++) {
        a[i] = dis[i] - i;
    }
    t2.build(1, 1, n, a);
    queue<int> q; 
    memset(p, -1, sizeof(p));
    q.push(j);
    p[j] = 0;
    t1.rmv(1, 1, n, j);
    t2.rmv(1, 1, n, j);
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        while (true) {
            auto u = t1.query(1, 1, n, curr - dis[curr], curr);
            if (u.first >= curr) {
                q.push(u.second);
                p[u.second] = p[curr] + 1;
                t1.rmv(1, 1, n, u.second);
                t2.rmv(1, 1, n, u.second);
            } else break;
        }    
        while (true) {
            auto u = t2.query(1, 1, n, curr, curr + dis[curr]);
            if (u.first >= -curr) {
                q.push(u.second);
                p[u.second] = p[curr] + 1;
                t1.rmv(1, 1, n, u.second);
                t2.rmv(1, 1, n, u.second);
            } else break;
        }
    }
    cout << p[k] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}