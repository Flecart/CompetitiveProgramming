#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll get_value(char ch) {
    return ch - 'a' + 1; 
}

ll get_value(string &s) {
    ll sum = 0;
    for (int i=  0; i < s.size(); i++) {
        sum += get_value(s[i]);
    }
    return sum;
}

void solve() {
    string s; cin >> s; 
    if (s.size() == 1) {
        cout << "Bob " << get_value(s) << '\n';
        return; 
    }    

    if (s.size() & 1) { // dispari
        ll bob;
        ll alice; 
        string ss;
        if (s[0] < s[s.size() - 1]) {
            bob = get_value(s[0]);
            ss = s.substr(1);
            alice = get_value(ss);
        } else {
            bob = get_value(s[s.size() - 1]); 
            ss = s.substr(0, s.size() - 1);
            alice = get_value(ss);
        }
        cout << "Alice " << alice - bob << '\n';

    } else {
        cout << "Alice " << get_value(s) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    while(n--) solve();
}