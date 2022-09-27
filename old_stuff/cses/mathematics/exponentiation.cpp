#include <bits/stdc++.h>

using namespace std;

const long long kMod = (int)1e9 + 7;

long long exp(int a, int b) {
    long long sol = 1LL;
    long long powers = a;
    while (b > 0) {
        if (b & 1) {
            sol *= powers;
            sol %= kMod;
        } 
        powers = (powers * powers) % kMod;
        b >>= 1;
    }
    return sol;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << exp(a, b) << '\n';
    }
}