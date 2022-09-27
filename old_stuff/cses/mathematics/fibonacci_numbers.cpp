#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct matrix {
    ll f[2];
    ll s[2];
};

/* FIBONACCI NUMBERS
using log(n) matrix fibonacci numbers computation.
the observation is, given the matrix
[ 1, 1],[1,0] if i multiply it by itself, at position 0,0
i should have the other fibo number. This could be proven inductively.

What i'm doing is fast exponentiation with this method.
*/

void add_one(matrix &res) {
    ll second_row[2] = {res.s[0], res.s[1]};
    res.s[0] = res.f[0]; res.s[1] = res.f[1];
    res.f[0] += second_row[0]; res.f[1] += second_row[1];
}

void double_matrix(matrix &matr) {
    matrix res;
    res.f[0] = matr.f[0] * matr.f[0] + matr.f[1] * matr.s[0];
    res.f[1] = matr.f[0] * matr.f[1] + matr.f[1] * matr.s[1];
    res.s[0] = matr.s[0] * matr.f[0] + matr.s[1] * matr.s[0];
    res.s[1] = matr.s[0] * matr.f[1] + matr.s[1] * matr.s[1];
    matr = res;
}

void normalize(matrix &matr) {
    ll mod = (ll) 1e9 + 7;
    matr.f[0] %= mod;
    matr.f[1] %= mod;
    matr.s[0] %= mod;
    matr.s[1] %= mod;
}

void solve(ll n, matrix &res) {
    if (n > 1) {
        solve(n / 2, res);
        double_matrix(res);
        if (n & 1) {
            add_one(res);
        }
        normalize(res);
    }
}

int main() {
    ll n; cin >> n; n--;
    if (n < 0) {
        cout << 0 << endl;
        return 0;
    }
    matrix res = {{1, 1}, {1, 0}};
    solve(n, res);
    cout << res.f[0] << endl;
}

