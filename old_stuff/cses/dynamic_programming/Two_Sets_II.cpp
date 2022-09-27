#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7; 
ll sum;
ll dp[501][250 * 501];

// L'osservazione principale è se ho un modo per trovare n (n + 1) / 4
// utilizzando tutti i numeri da 1 a n, allora il resto è fissato, e deve
// anche lui dare quel valore. Se non posso fare questa fivisione è impossibile
// quindi ritorno 0.
// allora mi faccio una dp(i, j) in cui i dice che posso utilizzare i valori
// da 1 a i, e j mi da la somma dei valori scelti. 
// allora per ogni n so che il valore che voglio ottenere è fissato (quel
// n * (n  + 1) / 4, e vedo i modi di ottenere questo valore da 1 fino a n)
// diviso alla fine per 2 questo valore perché li ho contati doppi)


void fill(int k, ll n) {
    dp[0][0] = 1;

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % mod; 
            else dp[i][j] = dp[i - 1][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; 
    cin >> n;
    sum = (n + 1) * n * 1ll / 2;
    fill(n, sum / 2 + 1);
    if (sum & 1) cout << 0 << endl; 
    else cout << dp[n][sum / 2] * ((mod + 1ll) / 2) % mod << endl;  // inverso moltiplicativo
}