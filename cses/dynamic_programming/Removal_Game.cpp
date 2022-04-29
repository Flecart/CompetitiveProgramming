#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int kmax = 5001;
const ll inf = 1e15;

ll dp[kmax][kmax]; 
bool preso[kmax][kmax]; // vero se prende destra, false se prende sinistra
int arr[kmax];

// returns the second max of a interval
ll get_second_max(int l, int h) {
    if (l >= h) return 0; // il gioco è già finito, non ci può essere un altro max
    else if (h - l == 1) return min(arr[l], arr[h]);
    else return preso[l][h] ? dp[l][h - 1] : dp[l + 1][h];
}

void fill_dp(int l, int h) {
    if (l == h) return dp[l][h] = arr[l], void();
    if (dp[l][h] != -inf) return;
    fill_dp(l + 1, h);
    fill_dp(l, h - 1);

    ll left = arr[l] + get_second_max(l + 1, h);
    ll right = arr[h] + get_second_max(l, h - 1);

    if (left > right) {
        preso[l][h] = false; 
        dp[l][h] = left;
    } else {
        preso[l][h] = true; 
        dp[l][h] = right;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < kmax; i++) {
        for (int j = 0; j < kmax; j++){
            dp[i][j] = -inf;
        }
    }
    fill_dp(0, n - 1);
    cout << dp[0][n - 1] << endl;
}