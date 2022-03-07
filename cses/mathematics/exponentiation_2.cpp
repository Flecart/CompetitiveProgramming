#include <bits/stdc++.h>

using namespace std;

const long long kMod = (int) 1e9 + 7;
const long long kExpMod = kMod - 1; // Little fermat theorem


long long exp(int a, int b, long long mod = kMod) {
    long long sol = 1LL;
    long long powers = a;
    while (b > 0) {
        if (b & 1) {
            sol *= powers;
            sol %= mod;
        } 
        powers = (powers * powers) % mod;
        b >>= 1;
    }
    return sol;
}

long long exp(int a, int b, int c, long long expMod, long long mod) {
    int exponent = exp(b, c, expMod);
    return exp(a, exponent, mod);
}

int main() {
    int n; cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        cout << exp(a, b, c, kExpMod, kMod) << '\n';
    }
}