#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 30

const int target = 1000000000;

int gcd(uint a, uint b) {
    if (a < b) swap(a, b);
    while (b != 0) {
        a %= b; 
        if (a < b) swap(a, b); 
    }
    return a;
}

int simulate(int a, int b) {
    return gcd(target + a, target + b);
}
// L'idea è ricavare il valore corrente in funzione di una query e il valore passato.
void solve() {
    int sol = 0; // ultimo resto
    for (int i = 1; i <= MAX; i++) {
        int last_pow = (1 << (i - 1));
        int curr_pow = (1 << i);
        cout << "? " << last_pow - sol << " " << last_pow - sol + curr_pow << endl; 

        int ans; 
        ans = simulate(last_pow - sol, last_pow - sol + curr_pow);
        // cin >> ans; 
        if (ans == curr_pow) sol += last_pow; 
    }
    cout << "! " << sol << endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n; 
    while (n--) {
        solve();
    }
}
