#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 5005

int dp[MAX][MAX]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, p;
    cin >> s >> p;
    // s lo metto a riga
    // p lo metto a colonna, e poi comncio
    for (int i = 0; i <= s.size(); i++) dp[i][0] = i;
    for (int i = 0; i <= p.size(); i++) dp[0][i] = i;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= p.size(); j++) {
            if (s[i - 1] == p[j - 1]) {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]) + 1);
            } else {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
    }
    // for (int i = 0; i <= s.size(); i++) {
    //     for (int j = 0; j <= p.size(); j++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    cout << dp[s.size()][p.size()];
}