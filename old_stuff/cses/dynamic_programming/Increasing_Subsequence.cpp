#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
ostream &operator<<(ostream &out, vector<int> &v) {
    for (auto i : v) {
        out << i << ' ';
    }
    return out; 
}
// find right index with binary search
int find_index(vector<int> &best, int n) {
    int l = -1, h = best.size(), mid; 
    while (l < h - 1) {
        mid = (l + h) / 2; 
        if (best[mid] < n) l = mid; 
        else h = mid; 
    }
    return h;
}
 
void process(vector<int> &best, int n) {
    int i = find_index(best, n);
    // cerr << best << endl;
    // cerr << n << ' ' << i << endl;
    if (i >= best.size()) best.push_back(n);
    else best[i] = n;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n; 
    vector<int> best; 
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        process(best, tmp);
    }
    cout << best.size() << '\n';
 
}