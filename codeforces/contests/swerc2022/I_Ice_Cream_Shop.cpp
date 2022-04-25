#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define SPACE 100ll

vector<int> people; 
vector<ll> limits; // nearest ice scream for each hut
set<int> ice_screams; // lmao, scream instead of cream

void fill_limits() {
    for (int i = 0; i < limits.size(); i++) {
        ll dist = i * SPACE; 
        auto nearest = ice_screams.lower_bound(dist);
        if (nearest != ice_screams.end()) {
            limits[i] = min(limits[i], *nearest - dist);
        }

        if (nearest != ice_screams.begin()) {
            nearest--;
            limits[i] = min(limits[i], dist - *nearest); 
        }
    }
}

void solve() {
    int n, m; 
    cin >> n >> m;
    ice_screams.clear();
    people.resize(n);
    limits.assign(n, 1ll * 1e12);
    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }
    for (int i = 0; i < m; i++) {
        int tmp; cin >> tmp;
        ice_screams.insert(tmp);
    }

    fill_limits();

    // get best answer
    queue<pair<ll, ll>> q; // cost, right
    ll sol = 0;
    ll curr = 0;
    for (int i = 0; i < n; i++) {
        ll left = i * SPACE - limits[i]; // left of i-esim hit
        while (!q.empty() and q.front().second <= left) {
            curr -= q.front().first;
            q.pop();
        }
        // se limits[i] è 0 è imprendibile!
        if (limits[i] != 0) {
            q.push({people[i], i * SPACE + limits[i]});
            curr += people[i];
        }
        if (curr > sol) sol = curr;
    }
    cout << sol << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}