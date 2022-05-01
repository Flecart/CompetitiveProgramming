#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int kmax = 2 * 1e5 + 2;
string s;
vector<bool> found(26); 
vector<char> period; 
void reset() {
    period.clear();
    found.assign(26, false);
}
void solve() { 
    cin >> s; 
    for (int i = 0; i < s.size(); i++) {
        if (!found[s[i] - 'a']) found[s[i] - 'a'] = true, period.push_back(s[i]); 
        else break; 
    }

    for (int i = period.size(); i < s.size(); i++) {
        if (s[i] != period[i % period.size()]) {
            reset();
            cout << "NO\n";
            return;
        }
    }
    reset();
    cout <<"YES\n"; return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}