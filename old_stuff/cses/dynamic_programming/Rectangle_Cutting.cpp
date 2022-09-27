#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAX 502
uint dp[MAX][MAX];

void fill_rect() {
    for (int i = 1; i < MAX; i++) {
        dp[1][i] = i - 1;
        dp[i][1] = dp[1][i];
        dp[i][i] = 0;
    }
    // poi cerca tutti i tagli possibili;
    // complete search possibile n^3
    for (int i = 2; i < MAX; i++) {
        for (int j = i; j < MAX; j++) {
            // checka tutti i tagli migliori possibili:
            for (int k = j - 1; k >= 1; k--) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
            for (int k = i - 1; k >= 1; k--) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            dp[j][i] = dp[i][j];
        }   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp)); // setta a infinito
    fill_rect();
    // for (int i = 1; i <= a; i++) {
    //     for (int j = 1; j <= b; j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    cout << dp[a][b] << endl;
}