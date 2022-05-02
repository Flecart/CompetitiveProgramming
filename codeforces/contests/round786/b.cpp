#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s; 

    int index = (s[0] - 'a') * 25; 
    int sum = 0;
    for (int i = 'a'; i < 'z' + 1; i++) {
        if (i == s[0]) continue; 
        sum += 1; 
        if (i == s[1]) break; 
    } 
    cout << index + sum << '\n';
    return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}