#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s; cin >> s; 
    cin >> n;
    map<char, int> ch;
    for (int i = 0; i < n; i++) {
        char c; cin >> c; 
        ch[c] = 1;
    }

    int start = 0;
    int max_range = 0;
    for (int i = 0; i < s.size(); i++) {
        if (ch[s[i]] == 1) {
            max_range = max(max_range, i - start);
            start = i;
        }
    }

    cout << max_range << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}