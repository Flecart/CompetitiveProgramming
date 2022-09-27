#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

void solve() {
    string s; 
    cin >> s; 
    int first = 0, second = 0;
    for (int i = 0; i < 3; i++) {
        first += s[i] - 'a';
    }

    for (int i = 3; i < 6; i++) {
        second += s[i] - 'a';
    }

    if (first == second) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}