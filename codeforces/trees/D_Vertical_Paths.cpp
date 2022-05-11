#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> adj;
vb printed;
struct dsu {
    vector<int> vv; 
    int n_sets;
    vector<vi> sols;
    dsu(int n) {
        vv.assign(n, -1);
        n_sets = n;
        sols.resize(n);
        for (int i = 0; i < n; i++) {
            sols[i] = vi(1, i);
        }
    }

    void join(int a, int b) {
        int ha = head(a);
        int hb = head(b);
        if (ha == hb) return; // same set
        if (vv[ha] < vv[hb]) {
            vv[ha] += vv[hb]; // the head contains the rank of the set
            vv[hb] = ha;
            sols[ha].push_back(hb);
        } else {
            vv[hb] += vv[ha];
            vv[ha] = hb;
            sols[hb].push_back(ha);
        }
        n_sets--;
    }

    int get_n() {return n_sets;}

    int head(int a) {
        if (vv[a] < 0) return a; // if negative, its a head
        return vv[a] = head(vv[a]); 
    }

    int size(int a) {
        return -vv[head(a)];
    }

    void print_till_end(int start) {
        int h = head(start);
        for (int i = sols[h].size() - 1; i >= 0; i--) {
            cout << sols[h][i] + 1 << ' ';
        }
        cout << '\n';
    }
};

void fill_set(int v, dsu &sets) {
    int mmax = -1;
    int mmax_idx;
    for (int n : adj[v]) {
        fill_set(n, sets);
        if (sets.size(n) > mmax) {
            mmax = sets.size(n);
            mmax_idx = n;
        }
    }

    if (mmax != -1) {
        sets.join(v, mmax_idx);
    }
}

void print_sol(int v, dsu &sets) {
    int repr = sets.head(v);
    if (!printed[repr]) {
        cout << sets.size(repr) << '\n';
        sets.print_till_end(v);
        printed[repr] = true;
    }

    for (int i : adj[v]) {
        print_sol(i, sets);
    }
}

void solve() {
    int n; 
    cin >> n;
    vi arr(n);
    dsu sets(n);
    adj.assign(n, vi());
    printed.assign(n, 0);
    int root;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];arr[i]--;
        if (i == arr[i]) {
            root = i;
            continue;
        }
        adj[arr[i]].push_back(i);
    }

    fill_set(root, sets);
    cout << sets.get_n() << '\n';
    print_sol(root, sets);
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}