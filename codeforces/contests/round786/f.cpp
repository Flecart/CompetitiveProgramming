#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};
FenwickTree *st;
vector<bool> screen;
int totals;
int k, m;

void solve() {
    int a, b; 
    cin >> a >> b; a--; b--;
    // cerr << a + b * m;
    if (screen[a + b * k]) {
        st->add(a + b * k, -1);
        totals--;
    } else {
        st->add(a + b * k, 1);
        totals++;
    }
    screen[a + b * k] = !screen[a + b * k];

    int in_segment = st->sum(0, totals - 1); // inclusive so 5
    cout << totals - in_segment << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> m;
    st = new FenwickTree(k * m);
    screen.resize(k * m);
    int n; cin >> n;
    char ch; 
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ch; 
            if (ch == '*') {
                st->add(i + j * k, 1);
                screen[i + j * k] = true;
                totals++;
            }
        }
    }
    while(n--) solve();
}