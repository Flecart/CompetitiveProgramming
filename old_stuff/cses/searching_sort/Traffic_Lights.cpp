#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

// TRAFFIC LIGHTS
// i use a map to keep track of the maximum of the segments
// and the set to keep the actual segments.
// so the insertion of the new traffic light is log n


set<int> s; // set of the lights

map<int, int> m; // map the lenght to n_segs with that len

ostream &operator<<(ostream &out, const pair<int, int> &segment) {
    out << segment.first << " " << segment.second << endl;
    return out;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, k; cin >> x >> k;
    int n; 
    s.insert(x);
    s.insert(0);
    m[x] = 1; 
    while(k--) {
        cin >> n;
        auto upper_segment = s.upper_bound(n); // trova il segmento in cui è compreso n
        auto lower_segment = upper_segment; lower_segment--;
        int len = *upper_segment - *lower_segment;
        s.insert(n);
        m[*upper_segment - n] += 1;
        m[n - *lower_segment] += 1;
        m[len] -= 1;
        if (m[len] <= 0) m.erase(len); // così non compare nel max dopo!

        // è il maggiore per come è ordinato
        cout << m.rbegin()->first << " ";

    }
}