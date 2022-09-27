#include <bits/stdc++.h>

using namespace std;
typedef long long ll;


struct info {
    ll all;
    ll prefix, suffix; 
    ll middle;
    info(int v): all(v), prefix(v), suffix(v), middle(v) {} 
    info(): info(0) {}

    // merges two info sections (in the right order)
    info operator+(const info &other) const {
        info new_info; 
        new_info.all = all + other.all; 
        new_info.prefix = max(prefix, max(all, all + other.prefix));
        new_info.suffix = max(other.suffix, max(other.all, other.all + suffix));
        new_info.middle = max(suffix + other.prefix, max(other.middle, middle));
        ll possibile_middle = max(new_info.all, max(suffix + other.all, all + other.prefix));
        new_info.middle = max(new_info.middle, possibile_middle); 
        return new_info;
    }

    void invert() {
        swap(prefix, suffix);
    }

    ostream &operator <<(ostream &out) const {
        out << all << " sol: " << middle << " p: " << prefix << " s: " << suffix  << endl; 
        return out;
    }
};

info solve(int l, int r, vector<int> &ref) {
    if (r - l == 1) return info(ref[l]); 
    int mid = (l + r) / 2;
    info left = solve(l, mid, ref);
    info right = solve(mid, r, ref);
    info sol = (left + right);
    // sol << cerr;
    return (left + right); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; 
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    info solution = solve(0, n, v); 
    cout << solution.middle;
}