#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = (int) 1e9 + 7;
#define MAX (int) 1e6 + 4
ll dp1[MAX]; // with middle bar
ll dp2[MAX]; // without 

void fill_dps() {
    // with has the middle stuff, without no
    // consider something like |- -|, and |-|-| 
    // the dash is upper stuf
    // we can count thet i can add |   |, |- -|, |-|-| to the first
    // and i can add |-| |, |-|-|, |- -| | |-|, | | | to the second
    dp1[1] = dp2[1] = 1;
    for (int i = 2; i < MAX; i++) {
        dp1[i] = (4 * dp1[i - 1] + dp2[i - 1]) % mod;
        dp2[i] = (dp1[i - 1] + 2 * dp2[i - 1]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x; cin >> n;
    fill_dps();
    while(n--) cin >> x, cout << (dp1[x] + dp2[x]) % mod << '\n';
}