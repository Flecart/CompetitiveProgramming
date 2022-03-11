#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x; cin >> x;
    int upper = sqrt(x);
    int count = 0;
    for (int i = 1; i <= upper; i++) {
        if (x % i == 0) count += 2;
    }
    if (upper * upper == x) count--;
    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}
