#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<class T>
ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto i : v) {
        out << i << ' ';
    }
    return out; 
}

template<class T, class K> 
ostream &operator<<(ostream &out, pair<T, K> &v) {
    cout << "(" << v.first << " " << v.second << ") ";
    return out; 
}

// find right index with binary search
int find_index(vector<ll> &best, ll n) {
    int l = -1, h = best.size(), mid; 
    while (l < h - 1) {
        mid = (l + h) / 2; 
        if (best[mid] <= n) l = mid; 
        else h = mid; 
    }
    return h;
}
 
void process(vector<ll> &best, ll n) {
    int i = find_index(best, n);
    // cerr << best << endl;
    // cerr << n << ' ' << i << endl;
    if (i >= best.size()) best.push_back(n);
    else best[i] = n;
}
 
int longest_increasing_subsequence(vector<pair<ll, ll>> &p) {
    vector<ll> best; 
    for (int i = 0; i < p.size(); i++) {
        process(best, p[i].second);
    }
    return best.size();
}

void solve() {
    int n, v; 
    cin >> n >> v; 
    vector<int> times(n);
    vector<int> dist(n);
    vector<pair<ll, ll>> xys; 
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }   
    for (int i = 0; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        if (1ll * v * times[i] < abs(dist[i])) continue; 
        xys.push_back({1ll * v * times[i] - dist[i], 1ll * v * times[i] + dist[i]});
    }
    sort(xys.begin(), xys.end()); 
    // cout << xys << endl;
    cout << longest_increasing_subsequence(xys) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}